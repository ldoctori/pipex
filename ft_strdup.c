/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:39:58 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/25 11:40:01 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		str_len;
	char	*copy;

	str_len = ft_strlen(src);
	copy = malloc(str_len + 1);
	if (copy == NULL)
		return (0);
	i = 0;
	while (i < str_len + 1)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
