/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:05 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:13:06 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (!haystack || !needle)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	while (*haystack)
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

char	*ft_strrstr(const char *haystack, const char *needle)
{
	size_t		i;
	const char	*hs_copy;

	if (!haystack || !needle)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	hs_copy = haystack + ft_strlen(haystack) - 1;
	while (hs_copy >= haystack)
	{
		i = 0;
		while (hs_copy[i] == needle[i] && hs_copy[i])
			i++;
		if (!needle[i])
			return ((char *)hs_copy);
		hs_copy--;
	}
	return (NULL);
}
