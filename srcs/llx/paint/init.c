/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:23:40 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 08:23:41 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint.h"
#include "llx_paint_internal.h"
#include "llx_win.h"

int	is_in_bound(t_paint *paint, t_point p)
{
	const t_bounds	b = paint->bounds;

	return (p.x >= b.x1 && p.x <= b.x2 && p.y >= b.y1 && p.y <= b.y2);
}

int	paint_init(t_paint *paint, t_llx_win *win)
{
	t_img_data	data;

	if (!paint || !win)
		return (0);
	paint->data = (uint32_t *)mlx_get_data_addr(win->cache, &data.pixel_bits,
			&data.line_bytes, &data.endian);
	if (!paint->data)
		return (0);
	paint->width = data.line_bytes / 4;
	paint->pen.ucolor = Llx_Black;
	paint->bounds = bounds(point(0, 0), point(win->width - 1, win->height - 1));
	return (1);
}

t_paint	*paint_set_color(t_paint *paint, t_color pen)
{
	if (paint)
		paint->pen = pen;
	return (paint);
}
