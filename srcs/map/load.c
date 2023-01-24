/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:24:07 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/23 02:24:09 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_internal.h"

static int	ends_with(char *str, char *end)
{
	const size_t	str_len = ft_strlen(str);
	const size_t	end_len = ft_strlen(end);

	if (end_len == 0 || str_len < end_len)
		return (0);
	str += str_len - end_len;
	return (ft_strcmp(str, end) == 0);
}

int	map_load(t_map *map, char *path, void *mlx)
{
	int		fd;
	char	*raw;
	int		res;

	ft_memset(map, 0, sizeof(t_map));
	if (!ends_with(path, ".cub"))
		return (ft_dprintf(2, INVALID_FORMAT, path), 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, OPEN_ERROR, path), 0);
	raw = read_all(fd);
	close(fd);
	if (!raw)
		return (ft_dprintf(2, BAD_ALLOC), 0);
	res = parse(map, raw, mlx);
	free(raw);
	return (res);
}

void	map_free(t_map *map)
{
	int	idx;

	idx = -1;
	while (++idx < 4)
		free(map->textures_path[idx]);
	free(map->data);
}
