/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimmed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:09 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:13:09 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrm_lead(char *str)
{
	if (!str)
		return (NULL);
	while (ft_is_whitespace(*str))
		str++;
	return (str);
}

char	*ft_strtrm_trail(char *str)
{
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = len - 1;
	while (i > 0 && ft_is_whitespace(str[i]))
		i--;
	if (i == 0 && ft_is_whitespace(str[i]))
		str[i] = '\0';
	else if (i != len - 1)
		str[i + 1] = '\0';
	return (str);
}

char	*ft_strtrm(char *str)
{
	if (!str)
		return (NULL);
	str = ft_strtrm_lead(str);
	str = ft_strtrm_trail(str);
	return (str);
}
