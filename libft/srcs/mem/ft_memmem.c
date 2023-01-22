/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:31:06 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/19 12:31:07 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmem(const void *haystack, size_t haystack_len,
			const void *needle, size_t needle_len)
{
	size_t		i;
	const void	*haystack_end;

	if (!haystack || !needle)
		return (NULL);
	if (!needle_len)
		return ((void *)haystack);
	haystack_end = haystack + haystack_len;
	while (haystack < haystack_end)
	{
		i = 0;
		while ((haystack + i) < haystack_end
			&& ((const char *)haystack)[i] == ((const char *)needle)[i])
			i++;
		if (i == needle_len)
			return ((void *)haystack);
		haystack++;
	}
	return (NULL);
}

void	*ft_memrmem(const void *haystack, size_t haystack_len,
				const void *needle, size_t needle_len)
{
	size_t		i;
	const void	*hs_copy;
	const void	*haystack_end;

	if (!haystack || !needle)
		return (NULL);
	if (!needle_len)
		return ((void *)haystack);
	haystack_end = haystack + haystack_len;
	hs_copy = haystack_end - 1;
	while (hs_copy >= haystack)
	{
		i = 0;
		while ((hs_copy + i) < haystack_end
			&& ((const char *)hs_copy)[i] == ((const char *)needle)[i])
			i++;
		if (i == needle_len)
			return ((void *)haystack);
		hs_copy++;
	}
	return (NULL);
}
