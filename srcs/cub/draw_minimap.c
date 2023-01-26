/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:06:00 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/25 01:06:01 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_map(t_paint *paint, t_map *map, float b_w, float b_h)
{
	size_t			x;
	size_t			y;
	t_rect			bloc;

	y = (size_t)-1;
	while (++y < map->height)
	{
		x = (size_t) - 1;
		while (++x < map->width)
		{
			bloc = rect(point(x * b_w, y * b_h), b_w, b_h);
			if (map->data[y * map->width + x] == EMPTY)
				paint_rect(paint_set_color(paint, (t_color)MM_BG), bloc);
		}
	}
}

static void	draw_player(t_paint *paint, t_player *player, float b_w, float b_h)
{
	const t_mat2x2	mat_rot_1 = mat2x2_rot(player->dir - FOV / 2);
	const t_mat2x2	mat_rot_2 = mat2x2_rot(player->dir + FOV / 2);
	const t_point	center = point(player->x * b_w, player->y * b_h);
	t_rect			bloc;
	t_vec2			arrow;

	bloc = rect(point(player->x * b_w - b_w / 6, player->y * b_h - b_h / 6),
			b_w / 3, b_h / 3);
	paint_rect(paint_set_color(paint, (t_color)MM_PLAYER), bloc);
	arrow = (t_vec2){MM_RANGE, 0.0f};
	mul_vec2_mat2x2(&arrow, mat_rot_1);
	arrow = (t_vec2){arrow.x + player->x * b_w, arrow.y + player->y * b_h};
	paint_line(paint, center, point(arrow.x, arrow.y));
	arrow = (t_vec2){MM_RANGE, 0.0f};
	mul_vec2_mat2x2(&arrow, mat_rot_2);
	arrow = (t_vec2){arrow.x + player->x * b_w, arrow.y + player->y * b_h};
	paint_line(paint, center, point(arrow.x, arrow.y));
}

void	cub_draw_minimap(t_cub *cub, t_paint *p)
{
	size_t	b_w;
	size_t	b_h;

	b_w = (float)(p->bounds.x2 - p->bounds.x1) / (float)cub->map.width;
	b_h = (float)(p->bounds.y2 - p->bounds.y1) / (float)cub->map.height;
	p->bounds.x2 = p->bounds.x1 + b_w * cub->map.width;
	p->bounds.y2 = p->bounds.y1 + b_h * cub->map.height;
	draw_map(p, &cub->map, b_w, b_h);
	draw_player(p, &cub->player, b_w, b_h);
}
