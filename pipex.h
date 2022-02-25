/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:10:38 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/25 14:11:53 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_struct
{
	char	**split;
	char	*s;
	char	c;
}	t_struct;

unsigned int	ft_strlen(const char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strstr(char *needle, char *haystack);
char			*ft_strdup(char *src);
char			*find_cmd_path(char **paths, char *cmd);
char			*find_file_path(char *file, char **env);
char			**ft_split(char *s, char c);
void			free_arr(char **arr);
void			exec_pid(char *argv[], char *envp[], int n);
void			some_checks(int argc, char **argv, char **envp, int *fd);
int				access_file(char *file, int open_flag, int std_fd, char **envp);

#endif
