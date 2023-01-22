/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:43:37 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/31 10:43:38 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*c_dst;
	const char	*c_src;

	if (!dst || !src)
		return (NULL);
	c_dst = dst;
	c_src = src;
	i = (size_t)-1;
	if (dst < src)
		while (++i < len)
			c_dst[i] = c_src[i];
	else
	{
		c_dst += len - 1;
		c_src += len - 1;
		while (++i < len)
			*c_dst-- = *c_src--;
	}
	return (dst);
}
