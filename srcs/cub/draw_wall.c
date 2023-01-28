/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:15:03 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/27 18:27:32 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_img_scaled_to(t_paint *paint, t_img *img, t_point p, float i_x)
{
	const float	size_ratio = (float)img->height / (float)p.y;
	const int	img_x = (float)img->width * i_x;
	int			y;
	int			y_off;
	uint32_t	*data;

	y_off = (WIN_HEIGHT - p.y) / 2;
	data = img->data;
	y = 0;
	if (y + y_off < 0)
		y = -y_off;
	while (y < p.y && y < WIN_HEIGHT - y_off)
	{
		paint->data[(y + y_off) * paint->width + p.x] = data[(int)(y
				* size_ratio) *img->width + img_x];
		y++;
	}
}

void	cub_draw_wall(t_map *map, t_paint *paint, t_wall wall)
{
	if (wall.face_idx < 0 || wall.face_idx > 3 || wall.height < 0.0f)
		return ;
	if (wall.face_x < 0.0f)
		wall.face_x = 0.0f;
	else if (wall.face_x > 1.0f)
		wall.face_x = 1.0f;
	wall.height *= (WIN_HEIGHT + 1.0f) / 2.0f;
	draw_img_scaled_to(paint, map->textures + wall.face_idx,
		point(wall.draw_x, wall.height * 2), wall.face_x);
}
