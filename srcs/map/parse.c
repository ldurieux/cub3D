/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:24:10 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/23 02:24:11 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_internal.h"

static int	skip_empty_lines(char **raw)
{
	char	*cpy;
	size_t	idx;

	cpy = *raw;
	idx = (size_t)-1;
	while (cpy[++idx])
	{
		if (!ft_is_whitespace(cpy[idx]) && ft_isprint(cpy[idx]))
		{
			*raw = cpy;
			return (1);
		}
		if (cpy[idx] == '\n')
		{
			cpy += idx + 1;
			idx = (size_t)-1;
		}
	}
	ft_dprintf(2, MAP_NOT_FOUND);
	return (0);
}

static void	get_map_size(t_map *map, char *raw)
{
	size_t	curr_width;
	int		empty;

	curr_width = 0;
	empty = 1;
	while (*raw)
	{
		curr_width++;
		if (!ft_is_whitespace(*raw))
			empty = 0;
		if (*raw == '\n')
		{
			if (!empty)
			{
				map->width = ft_max(map->width, curr_width - 1);
				map->height++;
			}
			curr_width = 0;
			empty = 1;
		}
		raw++;
	}
}

int	parse(t_map *map, char *raw)
{
	if (!parse_metadata(map, &raw))
		return (0);
	if (!skip_empty_lines(&raw))
		return (0);
	get_map_size(map, raw);
	return (1);
}
