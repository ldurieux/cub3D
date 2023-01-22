/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:07:11 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/31 14:07:12 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	size_t			str_len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str_len = ft_strlen(s);
	res = malloc(sizeof(char) * (str_len + 1));
	if (!res)
		return (NULL);
	res[0] = 0;
	res[str_len] = 0;
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
