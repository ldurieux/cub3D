/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:46:01 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/08 14:46:03 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	const char	*str_cp;

	if (!str)
		return (NULL);
	chr = (unsigned char)chr;
	str_cp = str + ft_strlen(str) - 1;
	if (chr == 0)
		return ((char *)str_cp + 1);
	while (str_cp >= str)
	{
		if (*str_cp == chr)
			return ((char *)str_cp);
		str_cp--;
	}
	return (NULL);
}
