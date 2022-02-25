/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:05:57 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/25 14:09:11 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	exec_pid(char *argv[], char *envp[], int n)
{
	int		i;
	char	**cmd_args;
	char	*str_of_paths;
	char	**paths;
	char	*valid_path;

	i = 0;
	cmd_args = ft_split(argv[n], ' ');
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			str_of_paths = envp[i] + 5;
			break ;
		}
		i++;
	}
	paths = ft_split(str_of_paths, ':');
	valid_path = find_cmd_path(paths, cmd_args[0]);
	execve(valid_path, cmd_args, envp);
	free(valid_path);
	free_arr(paths);
	free_arr(cmd_args);
}

int	access_file(char *file, int open_flag, int std_fd, char **envp)
{
	int		file_fd;
	char	*file_path;
	int		access_mode;

	file_path = find_file_path(file, envp);
	if (std_fd == STDIN_FILENO && access(file_path, R_OK) != 0)
	{
		free(file_path);
		return (1);
	}
	if (std_fd == STDOUT_FILENO)
		file_fd = open(file_path, open_flag, 0644);
	else
		file_fd = open(file_path, open_flag);
	if (file_fd == -1)
	{
		free(file_path);
		return (1);
	}
	dup2(file_fd, std_fd);
	close(file_fd);
	free(file_path);
	return (0);
}

void	some_checks(int argc, char **argv, char **envp, int *fd)
{
	if (argc != 5)
	{
		errno = 5;
		perror("Invalid number of arguments!");
		exit(EXIT_SUCCESS);
	}
	if (pipe(fd) == -1)
	{
		errno = 4;
		perror("Can't create the pipe!");
		exit(EXIT_SUCCESS);
	}
	if (access_file(argv[1], O_RDONLY, STDIN_FILENO, envp) != 0
		||access_file(argv[4], O_RDWR | O_CREAT | O_TRUNC,
			STDOUT_FILENO, envp) != 0)
	{
		errno = 2;
		perror("Can't open file!");
		exit(EXIT_SUCCESS);
	}
}
