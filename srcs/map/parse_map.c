/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:39:34 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/23 14:39:36 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_internal.h"

static int	parse_line(t_map *map, size_t line_idx, char *raw)
{
	size_t	idx;

	idx = (size_t)-1;
	while (raw[++idx] != '\n')
	{
		if (raw[idx] == ' ')
			continue ;
		if (!raw[idx])
			break ;
		if (!ft_strchr(MAP_CHRS, raw[idx]))
			return (ft_dprintf(2, MAP_UNEX_CHR), 0);
		if (raw[idx] == '0' || raw[idx] == '1' || raw[idx] == '2')
			map->data[line_idx * map->width + idx] = raw[idx] - '0' + 1;
		if (raw[idx] == '0' || raw[idx] == '1' || raw[idx] == '2')
			continue ;
		if (map->spawn.x != 0 && map->spawn.y != 0)
			return (ft_dprintf(2, MAP_MULTI_SPAWN), 0);
		map->data[line_idx * map->width + idx] = EMPTY;
		map->spawn.x = idx;
		map->spawn.y = line_idx;
		map->spawn.dir = (raw[idx] == 'N') * NORTH
			+ (raw[idx] == 'S') * SOUTH + (raw[idx] == 'E') * EAST
			+ (raw[idx] == 'W') * WEST;
	}
	return (1);
}

static int	check_borders(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = (size_t)-1;
	while (++x < map->width)
		if (map->data[y * map->width + x] & EMPTY)
			return (0);
	y = map->height - 1;
	x = (size_t)-1;
	while (++x < map->width)
		if (map->data[y * map->width + x] & EMPTY)
			return (0);
	y = (size_t)-1;
	x = 0;
	while (++y < map->height)
		if (map->data[y * map->width + x] & EMPTY)
			return (0);
	y = (size_t)-1;
	x = map->width - 1;
	while (++y < map->height)
		if (map->data[y * map->width + x] & EMPTY)
			return (0);
	return (1);
}

static int	is_closed(t_map *map)
{
	size_t	x;
	size_t	y;

	if (!check_borders(map))
		return (ft_dprintf(2, MAP_NOT_CLOSED), 0);
	y = 0;
	while (++y < map->height - 1)
	{
		x = 0;
		while (++x < map->width - 1)
		{
			if (!(map->data[y * map->width + x] & EMPTY))
				continue ;
			if (map->data[y * map->width + (x - 1)] == 0
				|| map->data[y * map->width + (x + 1)] == 0
				|| map->data[(y - 1) * map->width + x] == 0
				|| map->data[(y + 1) * map->width + x] == 0)
				return (ft_dprintf(2, MAP_NOT_CLOSED), 0);
		}
	}
	return (1);
}

int	parse_map(t_map *map, char *raw)
{
	size_t	line_idx;

	line_idx = (size_t)-1;
	while (++line_idx < map->height)
	{
		if (!*raw)
			return (ft_dprintf(2, MAP_UNEX_CHR), 0);
		if (*raw == '\n')
			break ;
		if (!parse_line(map, line_idx, raw))
			return (0);
		while (*raw && *raw != '\n')
			raw++;
		raw += *raw == '\n';
	}
	if (map->spawn.x == 0 && map->spawn.y == 0)
		return (ft_dprintf(2, MAP_NO_SPAWN), 0);
	return (is_closed(map));
}
