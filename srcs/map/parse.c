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
#include "mlx.h"
#include "llx_win_internal.h"

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
			idx = (size_t) - 1;
		}
	}
	ft_dprintf(2, MAP_NOT_FOUND);
	return (0);
}

static void	get_map_size(t_map *map, char *raw)
{
	size_t		curr_width;
	int			empty;

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

static int	parse_textures(t_map *map, void *mlx)
{
	int			idx;
	t_img		*tex;
	t_img_data	data;

	idx = -1;
	while (++idx < 4)
	{
		tex = map->textures + idx;
		tex->addr = mlx_xpm_file_to_image(mlx, map->textures_path[idx],
				&tex->width, &tex->height);
		if (!tex->addr)
			return (ft_dprintf(2, XPM_INVALID), 0);
		tex->data = (uint32_t *)mlx_get_data_addr(tex->addr, &data.pixel_bits,
				&data.line_bytes, &data.endian);
		free(map->textures_path[idx]);
		map->textures_path[idx] = NULL;
	}
	return (1);
}

int	parse(t_map *map, char *raw, void *mlx)
{
	if (!parse_metadata(map, &raw))
		return (0);
	if (!skip_empty_lines(&raw))
		return (0);
	get_map_size(map, raw);
	if (map->width == 0 || map->height == 0)
		return (ft_dprintf(2, MAP_DATA_NOT_FOUND), 0);
	map->data = malloc(sizeof(uint8_t) * map->width * map->height);
	if (!map->data)
		return (ft_dprintf(2, BAD_ALLOC), 0);
	ft_memset(map->data, 0, sizeof(uint8_t) * map->width * map->height);
	if (!parse_map(map, raw))
		return (0);
	return (parse_textures(map, mlx));
}
