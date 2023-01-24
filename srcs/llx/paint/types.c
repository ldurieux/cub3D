/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:23:43 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 08:23:45 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_paint.h"

t_point	point(int16_t x, int16_t y)
{
	return ((t_point){x, y});
}

t_rect	rect(t_point p, int16_t w, int16_t h)
{
	return ((t_rect){p.x, p.y, w, h});
}

t_bounds	bounds(t_point p1, t_point p2)
{
	return ((t_bounds){p1.x, p1.y, p2.x, p2.y});
}

t_color	color(uint32_t color)
{
	return ((t_color){color});
}
