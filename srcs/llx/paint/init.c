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
#include "llx_win.h"

int	paint_init(t_paint *paint, t_llx_win *win)
{
	if (!paint || !win)
		return (0);
	paint->win = win;
	paint->data = llx_win_cache(win);
	if (!paint->data)
		return (0);
	paint->width = win->width;
	paint->pen.ucolor = Llx_Black;
	paint->bounds = bounds(point(0, 0), point(win->width - 1, win->height - 1));
	return (1);
}

t_paint	*paint_set_bounds(t_paint *paint, t_bounds bounds)
{
	if (!paint)
		return (NULL);
	bounds.x1 = (bounds.x1 >= 0) * bounds.x1;
	bounds.y1 = (bounds.y1 >= 0) * bounds.y1;
	if (bounds.x2 >= paint->win->width)
		bounds.x2 = paint->win->width - 1;
	if (bounds.y2 >= paint->win->height)
		bounds.y2 = paint->win->height - 1;
	paint->bounds = bounds;
	return (paint);
}

t_paint	*paint_reset_bounds(t_paint *paint)
{
	if (!paint)
		return (NULL);
	paint->bounds.x1 = 0;
	paint->bounds.y1 = 0;
	paint->bounds.x2 = paint->win->width - 1;
	paint->bounds.y2 = paint->win->height - 1;
	return (paint);
}

t_paint	*paint_set_color(t_paint *paint, t_color pen)
{
	if (paint)
		paint->pen = pen;
	return (paint);
}
