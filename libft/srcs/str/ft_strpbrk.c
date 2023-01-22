/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:32:47 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 17:32:48 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_match_one_of(const char chr, const char *array)
{
	while (*array)
		if (chr == *array++)
			return (1);
	return (0);
}

char	*ft_strpbrk(const char *str, const char *chrs)
{
	if (!str || !chrs)
		return (NULL);
	while (*str)
		if (ft_match_one_of(*str++, chrs))
			return ((char *)str - 1);
	return (NULL);
}
