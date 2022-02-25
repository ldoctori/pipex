/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:30:02 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/25 11:30:13 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd_path(char **paths, char *cmd)
{
	char	*valid_path;
	int		i;

	i = 0;
	cmd = ft_strjoin("/", cmd);
	while (paths[i])
	{
		valid_path = ft_strjoin(paths[i], cmd);
		if (access(valid_path, X_OK) == 0)
		{
			free(cmd);
			return (valid_path);
		}
		free(valid_path);
		i++;
	}
	free(cmd);
	errno = 1;
	perror("Command not found!");
	exit(EXIT_SUCCESS);
	return (0);
}

char	*find_file_path(char *file, char **envp)
{
	int		i;
	char	*file_path;

	i = 0;
	file = ft_strjoin("/", file);
	file_path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PWD=", envp[i], 4) == 0)
		{
			file_path = envp[i] + 4;
			break ;
		}
		i++;
	}
	if (!file_path)
		return (0);
	file_path = ft_strjoin(file_path, file);
	free(file);
	return (file_path);
}
