/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:41:39 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/25 14:10:19 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pid_in(char **argv, char **envp, int *fd)
{
	int	pid1;

	pid1 = fork();
	if (pid1 < 0)
	{
		errno = 3;
		perror("Can't create the fork!");
		exit(EXIT_SUCCESS);
	}
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_pid(argv, envp, 2);
	}
	return (pid1);
}

int	pid_out(char **argv, char **envp, int *fd)
{
	int	pid2;

	pid2 = fork();
	if (pid2 < 0)
	{
		errno = 3;
		perror("Can't create the fork!");
		exit(EXIT_SUCCESS);
	}
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_pid(argv, envp, 3);
	}
	return (pid2);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	some_checks(argc, argv, envp, fd);
	pid1 = pid_in(argv, envp, fd);
	pid2 = pid_out(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
