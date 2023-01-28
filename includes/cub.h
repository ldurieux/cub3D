/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:18:03 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/27 16:31:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define MM_BG 0x00aaaaaa
# define MM_PLAYER 0x004499ff
# define MM_RANGE 15.0f

//FOV = 90.0f / 180.0f * M_PI
# define FOV 1.57079632679

# define ROT_SPEED 0.05f
# define MOVE_SPEED 0.1f

# include <stddef.h>
# include <math.h>
# include "map.h"
# include "matrix.h"
# include "llx.h"
# include "llx_win.h"
# include "llx_paint.h"

typedef struct s_player
{
	float	x;
	float	y;
	float	dir;
	float	dir_x;
	float	dir_y;
	float	pla_x;
	float	pla_y;
}	t_player;

typedef struct s_cub
{
	t_map		map;
	t_player	player;
	t_bounds	mm_bounds;
	t_point		last_mouse_pos;
}	t_cub;

typedef struct s_wall
{
	int		face_idx;
	float	face_x;
	float	height;
	int		draw_x;
}	t_wall;

int		cub_init(t_cub *cub, char *file, void *mlx);
void	cub_free(t_cub *cub);

void	cub_on_key(t_cub *cub, t_llx_win *win);
void	cub_on_mouse(t_cub *cub, t_llx_win *win);

void	cub_draw_background(t_cub *cub, t_paint *paint);
void	cub_draw_game(t_cub *cub, t_paint *paint);
void	cub_draw_minimap(t_cub *cub, t_paint *paint);

void	cub_draw_wall(t_map *map, t_paint *paint, t_wall wall);

#endif // CUB_H
