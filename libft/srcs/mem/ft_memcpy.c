/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:48 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:49 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;

	if (dst == src)
		return (dst);
	c_dst = (char *)dst;
	c_src = (char *)src;
	while (len--)
	{
		*c_dst = *c_src;
		c_dst++;
		c_src++;
	}
	return (dst);
}
