/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:41:20 by ldoctori          #+#    #+#             */
/*   Updated: 2022/01/25 11:41:21 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strstr(char *needle, char *haystack)
{
	char	*ptr;
	int		needle_len;

	if (needle == 0 || haystack == 0)
		return (0);
	needle_len = ft_strlen(needle);
	ptr = ft_strchr(haystack, *needle);
	if (!ptr)
		return (0);
	while (ft_strncmp(needle, ptr, needle_len) != 0)
	{
		ptr = ft_strchr(ptr + 1, *needle);
		if (!ptr)
			return (0);
	}
	return (ptr);
}
