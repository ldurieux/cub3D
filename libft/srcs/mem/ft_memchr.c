/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:55:20 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/31 10:55:21 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *data, int chr, size_t len)
{
	size_t			i;
	unsigned char	*c_data;

	if (!data)
		return (NULL);
	c_data = (unsigned char *)data;
	chr = (unsigned char)chr;
	i = (size_t)-1;
	while (++i < len)
	{
		if (*c_data == chr)
			return ((void *)c_data);
		c_data++;
	}
	return (NULL);
}
