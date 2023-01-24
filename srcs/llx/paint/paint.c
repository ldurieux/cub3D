/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:23:42 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 08:23:43 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint.h"

static int	is_in_bound(t_paint *paint, t_point p)
{
	const t_bounds	b = paint->bounds;

	return (p.x >= b.x1 && p.x <= b.x2 && p.y >= b.y1 && p.y <= b.y2);
}

void	paint_pixel(t_paint *paint, t_point p)
{
	if (!paint)
		return ;
	p.x += paint->bounds.x1;
	p.y += paint->bounds.y1;
	if (!is_in_bound(paint, p))
		return ;
	paint->data[p.y * paint->width + p.x] = paint->pen.ucolor;
}

void	paint_rect(t_paint *paint, t_rect rect)
{
	t_bounds	saved;
	t_bounds	res;

	if (!paint)
		return ;
	saved = paint->bounds;
	rect.x += paint->bounds.x1;
	rect.y += paint->bounds.y1;
	res = bounds(point(rect.x, rect.y),
			point(rect.x + rect.w - 1, rect.y + rect.h - 1));
	if (saved.x1 > res.x1)
		res.x1 = saved.x1;
	if (saved.y1 > res.y1)
		res.y1 = saved.y1;
	if (saved.x2 < res.x2)
		res.x2 = saved.x2;
	if (saved.y2 < res.y2)
		res.y2 = saved.y2;
	paint->bounds = res;
	paint_fill(paint);
	paint->bounds = saved;
}

void	paint_fill(t_paint *paint)
{
	int16_t		x;
	int16_t		y;
	uint32_t	color;

	if (!paint)
		return ;
	color = paint->pen.ucolor;
	y = paint->bounds.y1 - 1;
	while (++y <= paint->bounds.y2)
	{
		x = paint->bounds.x1 - 1;
		while (++x <= paint->bounds.x2)
			paint->data[y * paint->width + x] = color;
	}
}
