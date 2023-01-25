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
	const int16_t	half_height = paint->win->height >> 1;
	t_map			*map;

	map = &cub->map;
	paint_set_color(paint, (t_color)map->colors[CEIL]);
	paint_rect(paint, rect(point(0, 0), INT16_MAX, half_height));
	paint_set_color(paint, (t_color)map->colors[FLOOR]);
	paint_rect(paint, rect(point(0, half_height), INT16_MAX, half_height));
}
