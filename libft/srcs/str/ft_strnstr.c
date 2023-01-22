/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:45:51 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/08 14:45:54 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	const char	*end;

	if (!haystack || !needle)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	end = haystack - ft_strlen(needle);
	if ((size_t)end > SIZE_MAX - len)
		end = (char *)SIZE_MAX;
	else
		end += len;
	while (*haystack && haystack <= end)
	{
		i = 0;
		while (haystack[i] == needle[i] && haystack[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
