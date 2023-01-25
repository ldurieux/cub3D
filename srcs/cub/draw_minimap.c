/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:06:00 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/25 01:06:01 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_draw_minimap(t_cub *cub, t_paint *paint)
{
	(void)cub;
	paint_set_color(paint, (t_color)Llx_Transparent);
	paint_fill(paint);
}
