/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:44:58 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/08 14:44:59 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dest || !src)
		return (0);
	i = 0;
	while (dest[i] && i < size)
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	j = 0;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (size > 0)
		dest[i + j] = '\0';
	j += ft_strlen(src + j);
	return (i + j);
}
