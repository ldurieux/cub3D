/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:26:35 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/22 17:26:39 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>

# include "libft.h"
# include "ft_printf.h"
# include "llx_paint.h"

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define FLOOR 0
# define CEIL 1

# define EMPTY 1
# define WALL 2
# define OPEN_DOOR 3
# define CLOSED_DOOR 4

typedef struct s_img	t_img;

typedef struct s_spawn
{
	size_t	x;
	size_t	y;
	uint8_t	direction;
}	t_spawn;

typedef struct s_map
{
	char	*textures_path[4];
	t_img	textures[4];
	t_rgba	colors[2];
	size_t	width;
	size_t	height;
	t_spawn	spawn;
	uint8_t	*data;
}	t_map;

int		map_load(t_map *map, char *path, void *mlx);
void	map_free(t_map *map);

#endif // MAP_H
