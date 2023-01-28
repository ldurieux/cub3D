/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:06:00 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/27 18:25:29 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_door(t_paint *paint, t_point p, t_vec2 b)
{
	const t_rect	bloc = rect(point(p.x + 5, p.y + 5), b.x - 10, b.y - 10);

	paint_rect(paint, bloc);
}

static void	draw_map(t_paint *paint, t_map *map, t_vec2 b)
{
	size_t	x;
	size_t	y;
	t_rect	bloc;
	uint8_t	val;

	y = (size_t)-1;
	while (++y < map->height)
	{
		x = (size_t) - 1;
		while (++x < map->width)
		{
			val = map->data[y * map->width + x];
			bloc = rect(point(x * b.x, y * b.y), b.x, b.y);
			if (val == EMPTY || val == OPEN_DOOR)
				paint_rect(paint, bloc);
			else if (val == CLOSED_DOOR)
				draw_door(paint, (t_point){x * b.x, y * b.y}, b);
		}
	}
}

static void	draw_player(t_paint *paint, t_player *player, t_vec2 b)
{
	const t_mat2x2	mat_rot = mat2x2_rot(player->dir);
	const t_point	center = point(player->x * b.x, player->y * b.y);
	t_rect			bloc;
	t_vec2			arrow;

	bloc = rect(point(player->x * b.x - 3, player->y * b.y - 3),
			6, 6);
	paint_rect(paint_set_color(paint, (t_color)MM_PLAYER), bloc);
	arrow = (t_vec2){MM_RANGE, 0.0f};
	mul_vec2_mat2x2(&arrow, mat_rot);
	arrow = (t_vec2){arrow.x + player->x * b.x, arrow.y + player->y * b.y};
	paint_line(paint, center, point(arrow.x, arrow.y));
}

void	cub_draw_minimap(t_cub *cub, t_paint *p)
{
	size_t	b_w;
	size_t	b_h;

	b_w = (float)(p->bounds.x2 - p->bounds.x1) / (float)cub->map.width;
	b_h = (float)(p->bounds.y2 - p->bounds.y1) / (float)cub->map.height;
	if (cub->map.width > cub->map.height)
		b_h *= (float)cub->map.height / (float)cub->map.width;
	else
		b_w *= (float)cub->map.width / (float)cub->map.height;
	p->bounds.x2 = p->bounds.x1 + b_w * cub->map.width;
	p->bounds.y2 = p->bounds.y1 + b_h * cub->map.height;
	paint_set_color(p, (t_color)MM_BG);
	draw_map(p, &cub->map, (t_vec2){b_w, b_h});
	draw_player(p, &cub->player, (t_vec2){b_w, b_h});
}
