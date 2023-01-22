/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:08:55 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/27 16:22:12 by ldurieux         ###   ########lyon.fr   */
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

static size_t	ft_count_words(const char *str, const char *delims)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (ft_match_one_of(*str, delims))
			str++;
		if (!*str)
			break ;
		while (*str && !ft_match_one_of(*str, delims))
			str++;
		count++;
	}
	return (count);
}

static char	**split_criterr(char **arr)
{
	size_t	idx;

	idx = (size_t)-1;
	while (arr[++idx])
		free(arr[idx]);
	free(arr);
	return (NULL);
}

char	**ft_strsplit(const char *str, const char *delims)
{
	size_t	words;
	size_t	i;
	char	**res;

	if (!str || !delims)
		return (NULL);
	words = ft_count_words(str, delims);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = (size_t)-1;
	while (++i < words)
	{
		res[i] = ft_strtok_r(str, delims, &str);
		if (!res[i])
			return (split_criterr(res));
	}
	res[i] = NULL;
	return (res);
}
