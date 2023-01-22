/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:25:36 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 16:25:37 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	src_len;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	res = malloc(sizeof(char) * (src_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, src, src_len);
	res[src_len] = '\0';
	return (res);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*res;
	size_t	src_len;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	if (n < src_len)
		src_len = n;
	res = malloc(sizeof(char) * (src_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, src, src_len);
	res[src_len] = '\0';
	return (res);
}
