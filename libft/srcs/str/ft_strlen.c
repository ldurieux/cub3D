/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:01 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:13:02 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res])
		res++;
	return (res);
}

size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res] && res < n)
		res++;
	return (res);
}
