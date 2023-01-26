/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:27:03 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/26 00:27:04 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint.h"

#define INSIDE 0x0
#define LEFT 0x1
#define RIGHT 0x2
#define BOTTOM 0x4
#define TOP 0x8

static void	draw_line(t_paint *paint, t_point a, t_point b)
{
	const t_point	delta = (t_point){abs(b.x - a.x), -abs(b.y - a.y)};
	const t_point	slope = (t_point){(a.x < b.x) * 2 - 1, (a.y < b.y) * 2 - 1};
	t_point			cond;
	int				error;
	int				e2;

	error = delta.x + delta.y;
	while (a.x != b.x || a.y != b.y)
	{
		paint->data[a.y * paint->width + a.x] = paint->pen.ucolor;
		e2 = error << 1;
		cond = (t_point){e2 <= delta.x, e2 >= delta.y};
		if ((cond.x && a.y == b.y) || (cond.y && a.x == b.x))
			return ;
		error += cond.x * delta.x + cond.y * delta.y;
		a = (t_point){a.x + cond.y * slope.x, a.y + cond.x * slope.y};
	}
	paint->data[a.y * paint->width + a.x] = paint->pen.ucolor;
}

static void	op_codes(t_paint *paint, t_point a, t_point b, uint8_t *codes)
{
	codes[0] = (a.x < paint->bounds.x1)
		| (a.x > paint->bounds.x2) << 1
		| (a.y < paint->bounds.y1) << 3 | (a.y > paint->bounds.y2) << 2;
	codes[1] = (b.x < paint->bounds.x1)
		| (b.x > paint->bounds.x2) << 1
		| (b.y < paint->bounds.y1) << 3 | (b.y > paint->bounds.y2) << 2;
}

static void	partial_clip(t_paint *paint, t_point *a, t_point *b, uint8_t *codes)
{
	const uint8_t	code_idx = codes[0] == 0;
	t_point			*dest;
	int				tmp;

	dest = a;
	if (code_idx == 1)
		dest = b;
	if (codes[code_idx] & (TOP | BOTTOM))
	{
		tmp = paint->bounds.y1;
		if (codes[code_idx] & BOTTOM)
			tmp = paint->bounds.y2;
		*dest = (t_point){a->x + (b->x - a->x) * (tmp - a->y) / (b->y - a->y),
			tmp};
	}
	else
	{
		tmp = paint->bounds.x1;
		if (codes[code_idx] & RIGHT)
			tmp = paint->bounds.x2;
		*dest = (t_point){tmp,
			a->y + (b->y - a->y) * (tmp - a->x) / (b->x - a->x)};
	}
}

void	paint_line(t_paint *paint, t_point a, t_point b)
{
	uint8_t	codes[2];

	if (!paint)
		return ;
	a = (t_point){a.x + paint->bounds.x1, a.y + paint->bounds.y1};
	b = (t_point){b.x + paint->bounds.x1, b.y + paint->bounds.y1};
	op_codes(paint, a, b, codes);
	while (codes[0] || codes[1])
	{
		if (codes[0] & codes[1])
			return ;
		partial_clip(paint, &a, &b, codes);
		op_codes(paint, a, b, codes);
	}
	draw_line(paint, a, b);
}
