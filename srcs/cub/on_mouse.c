/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:58:04 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/26 07:58:05 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_on_mouse(t_cub *cub, t_llx_win *win)
{
	float	val;

	if (llx_win_is_btn_down(win, LlxBtn_Left))
	{
		val = win->mouse_pos.x - cub->last_mouse_pos.x;
		val /= 200;
		cub->player.dir -= val;
	}
	cub->last_mouse_pos = win->mouse_pos;
}
