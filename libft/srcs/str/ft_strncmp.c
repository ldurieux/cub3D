/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:45:42 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/08 14:45:43 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*r1;
	const unsigned char	*r2;

	r1 = (const unsigned char *)s1;
	r2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	if (!r1 || !r2)
		return ((int)(r1 - r2));
	while (*r1 == *r2 && *r1 && n-- > 1)
	{
		r1++;
		r2++;
	}
	return (*r1 - *r2);
}
