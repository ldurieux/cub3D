/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:15:52 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/31 13:15:54 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	if (!s1 || !set)
		return (NULL);
	if (!*set || !*s1)
		return (ft_strdup(s1));
	start = (unsigned int)ft_strspn(s1, set);
	len = ft_strlen(s1) - start - ft_strrspn(s1, set);
	if (len <= 0)
		return (NULL);
	return (ft_substr(s1, start, len));
}
