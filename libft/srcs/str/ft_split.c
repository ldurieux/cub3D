/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:44:44 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/08 14:44:46 by ldurieux         ###   ########lyon.fr   */
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

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	char	delims[2];
	char	**res;

	if (!s)
		return (NULL);
	delims[0] = c;
	delims[1] = '\0';
	words = ft_count_words(s, delims);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = (size_t)-1;
	while (++i < words)
	{
		res[i] = ft_strtok_r(s, delims, &s);
		if (!res[i])
			return (split_criterr(res));
	}
	res[i] = NULL;
	return (res);
}
