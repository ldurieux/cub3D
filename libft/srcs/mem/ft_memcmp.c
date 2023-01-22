/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:02:25 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/31 11:02:26 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*r1;
	const unsigned char	*r2;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	if (!r1 || !r2)
		return ((int)(r1 - r2));
	if (len == 0)
		return (0);
	while (*r1 == *r2 && len-- > 1)
	{
		r1++;
		r2++;
	}
	return (*r1 - *r2);
}
