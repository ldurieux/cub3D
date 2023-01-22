/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:32:51 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 17:32:53 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok_r(const char *str, const char *delims,
				const char **save_ptr)
{
	const char	*end;
	char		*res;

	if (!str || !delims)
		return (NULL);
	str += ft_strspn(str, delims);
	end = ft_strpbrk(str, delims);
	if (!end)
		end = str + ft_strlen(str);
	if (end - str == 0)
		return (NULL);
	res = ft_strndup(str, end - str);
	if (save_ptr)
		*save_ptr = end;
	return (res);
}
