/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsimplified.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:03 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:13:04 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsmp(char *str)
{
	size_t	to_idx;
	size_t	from_idx;

	if (!str)
		return (NULL);
	str = ft_strtrm(str);
	from_idx = 0;
	to_idx = 0;
	while (str[from_idx])
	{
		if (ft_is_whitespace(str[from_idx]))
		{
			while (ft_is_whitespace(str[from_idx]))
				from_idx++;
			str[to_idx++] = ' ';
		}
		str[to_idx++] = str[from_idx++];
	}
	str[to_idx] = '\0';
	return (str);
}
