/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:18:03 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/25 00:18:04 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define WIN_WIDTH 1366
# define WIN_HEIGHT 768

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
	float	height;
	float	dir;
}	t_player;

typedef struct s_cub
{
	t_map		map;
	t_player	player;
	t_bounds	mm_bounds;
}	t_cub;

int		cub_init(t_cub *cub, char *file, void *mlx);
void	cub_free(t_cub *cub);

void	cub_on_key(t_cub *cub, t_llx_win *win);

void	cub_draw_background(t_cub *cub, t_paint *paint);
void	cub_draw_game(t_cub *cub, t_paint *paint);
void	cub_draw_minimap(t_cub *cub, t_paint *paint);

#endif // CUB_H
