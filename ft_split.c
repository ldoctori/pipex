/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:36:20 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/25 11:36:24 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_split_allocate(t_struct *ss)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (ss->s[i] != '\0')
	{
		if (ss->s[i] == ss->c)
		{
			while (ss->s[i] == ss->c)
				i++;
			if (!(ss->s[i]))
				break ;
			count++;
			continue ;
		}
		i++;
	}
	ss->split = malloc((count + 2) * sizeof(char *));
}

char	**free_all(t_struct *ss)
{
	unsigned int	elem;

	elem = 0;
	while (ss->split[elem])
	{
		free(ss->split[elem]);
		elem++;
	}
	free(ss->split);
	return (0);
}

void	ft_alloc_elem(t_struct *ss, unsigned int elem)
{
	char			*ptr;
	unsigned int	len;

	len = 0;
	ptr = ss->s;
	while (*ptr != ss->c && *ptr)
	{
		ptr++;
		len++;
	}
	ss->split[elem] = malloc(len + 1);
	if (!(ss->split[elem]))
	{
		ss->split = free_all(ss);
		return ;
	}
	len = 0;
	while (*(ss->s) != ss->c && *(ss->s))
	{
		ss->split[elem][len] = *(ss->s);
		ss->s++;
		len++;
	}
	ss->split[elem][len] = '\0';
}

int	ft_rec(t_struct *ss, unsigned int elem)
{
	while (*(ss->s) == ss->c && *(ss->s))
		ss->s++;
	if (!(*(ss->s)))
	{
		ss->split[elem] = 0;
		return (0);
	}
	ft_alloc_elem(ss, elem);
	return (ft_rec(ss, elem + 1));
}

char	**ft_split(char *s, char c)
{
	t_struct	ss;

	if (!s)
		return (0);
	ss.s = s;
	ss.c = c;
	ft_split_allocate(&ss);
	if (!ss.split)
		return (0);
	ft_rec(&ss, 0);
	return (ss.split);
}
