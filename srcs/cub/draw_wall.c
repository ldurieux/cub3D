/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:15:03 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/27 16:15:04 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#include <stdio.h>
void	cub_draw_wall(t_map *map, t_paint *paint, t_wall wall)
{
	int			img_height;
	t_img		*img;
	t_point		w_pos;
	t_point		i_pos;
	uint16_t	y_end;

	if (wall.face_idx < 0 || wall.face_idx > 3 || wall.face_x < 0.0f
		|| wall.face_x > 1.0f || wall.height < 0.0f)
		return ;
	img_height = map->textures[wall.face_idx].height;
	img = (map->textures + wall.face_idx);
	i_pos.x = map->textures[wall.face_idx].width * wall.face_x;
	i_pos.y = 0;
	w_pos.x = wall.draw_x;
	y_end = (WIN_HEIGHT + WIN_HEIGHT * wall.height) / 2;
	w_pos.y = WIN_HEIGHT - y_end - 1;
	if (w_pos.y < 0)
		w_pos.y = -1;
	while (++w_pos.y < y_end)
	{
		if (w_pos.y >= WIN_HEIGHT)
			break ;
		i_pos.y = img_height * ((float)(w_pos.y - (WIN_HEIGHT - y_end))
			/ (WIN_HEIGHT * wall.height));
		if (i_pos.y > 10 || i_pos.y < 0)
			continue ;
		paint->data[w_pos.y * paint->width + w_pos.x] = img->data[i_pos.y
			* img->width + i_pos.x];
	}
}
