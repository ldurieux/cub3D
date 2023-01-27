/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:18:00 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/25 00:18:03 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_draw_background(t_cub *cub, t_paint *paint)
{
	uint32_t		*data;
	t_map			*map;
	uint32_t		color;
	size_t			idx;
	size_t			end;

	data = paint->data;
	map = &cub->map;
	color = ((t_color)map->colors[CEIL]).ucolor;
	idx = (size_t)-1;
	end = WIN_WIDTH * WIN_HEIGHT / 2;
	while (++idx < end)
		data[idx] = color;
	color = ((t_color)map->colors[FLOOR]).ucolor;
	end <<= 1;
	while (++idx < end)
		data[idx] = color;
}
