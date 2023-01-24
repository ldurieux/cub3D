/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_metadata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:24:12 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/23 02:24:13 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_internal.h"

static int	get_color(uint8_t *color, char **raw)
{
	char	*cpy;
	int		tmp;

	cpy = *raw;
	tmp = ft_strtoi(cpy, raw);
	if (tmp < 0 || tmp > 255)
		return (ft_dprintf(2, COLOR_INVALID), 0);
	*color = (uint8_t)tmp;
	return (1);
}

static int	parse_color(t_rgba *color, char **raw)
{
	char	*cpy;

	cpy = *raw;
	if (!ft_isdigit(*cpy))
		return (ft_dprintf(2, COLOR_UNEX_CHR), 0);
	if (!get_color(&color->r, &cpy))
		return (0);
	if (!eat_inter_color(&cpy))
		return (0);
	if (!get_color(&color->g, &cpy))
		return (0);
	if (!eat_inter_color(&cpy))
		return (0);
	if (!get_color(&color->b, &cpy))
		return (0);
	cpy = eat_spaces(cpy);
	if (*cpy != '\n')
		return (ft_dprintf(2, COLOR_UNEX_CHR), 0);
	*raw = cpy;
	return (1);
}

static int	parse_field(t_map *map, char **raw, t_field field)
{
	char	*cpy;
	int		struct_idx;
	size_t	idx;

	cpy = *raw;
	if (ft_is_whitespace(*cpy) || !ft_isprint(*cpy))
		return (ft_dprintf(2, METADATA_UNEX_NL), 0);
	if (field == Floor_Col || field == Ceil_Col)
	{
		if (!parse_color(map->colors + (field == Ceil_Col), &cpy))
			return (0);
		*raw = cpy;
		return (1);
	}
	struct_idx = (field == North_Tex) * NORTH + (field == South_Tex) * SOUTH
		+ (field == East_Tex) * EAST + (field == West_Tex) * WEST;
	idx = (size_t) - 1;
	while (!ft_is_whitespace(cpy[++idx]))
		;
	map->textures_path[struct_idx] = ft_substr(cpy, 0, idx);
	if (!map->textures_path[struct_idx])
		return (ft_dprintf(2, BAD_ALLOC), 0);
	*raw = cpy + idx;
	return (1);
}

static int	read_field(t_map *map, char **raw, uint32_t *fields)
{
	char		*cpy;
	uint32_t	idx;
	size_t		len;
	const char	*strs[6] = {"NO", "SO", "EA", "WE", "F", "C"};

	cpy = *raw;
	idx = (uint32_t)-1;
	while (++idx < 6)
		if (ft_strncmp(cpy, strs[idx], ft_strlen(strs[idx])) == 0)
			break ;
	if (idx >= 6)
		return (ft_dprintf(2, METADATA_INVALID_HEADER), 0);
	len = ft_strlen(strs[idx]);
	idx = 1 << idx;
	if (*fields & idx)
		return (ft_dprintf(2, METADATA_DUPLICATE_HEADER), 0);
	*fields |= idx;
	cpy = eat_spaces(cpy + len);
	if (!parse_field(map, &cpy, idx))
		return (0);
	cpy = eat_spaces(cpy);
	if (*cpy != '\n')
		return (ft_dprintf(2, METADATA_UNEX_CHR), 0);
	*raw = cpy;
	return (1);
}

int	parse_metadata(t_map *map, char **raw)
{
	int			remaining;
	uint32_t	fields;
	int			idx;
	int			fd;

	fields = 0;
	remaining = 7;
	while (--remaining > 0)
	{
		*raw = eat_whitespace(*raw);
		if (ft_isdigit(**raw) || **raw == '\0')
			return (ft_dprintf(2, METADATA_MISSING), 0);
		if (!read_field(map, raw, &fields))
			return (0);
	}
	idx = -1;
	while (++idx < 4)
	{
		fd = open(map->textures_path[idx], O_RDONLY);
		if (fd == -1)
			return (ft_dprintf(2, OPEN_ERROR, map->textures_path[idx]), 0);
		close(fd);
	}
	return (1);
}
