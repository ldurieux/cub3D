/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:46:34 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/14 19:46:36 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BITS_IN_BYTE 8

static uint64_t	make_mask(const uint8_t value)
{
	uint64_t	res;
	uint8_t		i;

	res = 0;
	i = 0;
	while (i++ < BITS_IN_BYTE)
		res = (res << BITS_IN_BYTE) + value;
	return (res);
}

void	*ft_memset(void *dst, int value, size_t len)
{
	uint8_t		*c_ptr;
	uint64_t	*i_ptr;
	uint64_t	mask;

	if (!dst)
		return (NULL);
	i_ptr = (uint64_t *) dst;
	mask = make_mask((uint8_t)value);
	while (len > BITS_IN_BYTE - 1)
	{
		*i_ptr++ = mask;
		len -= BITS_IN_BYTE;
	}
	c_ptr = (uint8_t *) i_ptr;
	while (len-- > 0)
		*c_ptr++ = (uint8_t)value;
	return (dst);
}
