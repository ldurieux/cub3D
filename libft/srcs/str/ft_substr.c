/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:15:20 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/31 12:15:21 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len < start)
		str_len = start;
	str_len -= start;
	if (len > str_len)
		len = str_len;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (len != 0)
		ft_strncpy(res, s + start, len);
	res[len] = '\0';
	return (res);
}
