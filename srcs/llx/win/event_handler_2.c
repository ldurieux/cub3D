/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:38:36 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 01:38:37 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_win_internal.h"
#include "llx_win.h"

void	llx_on_enter(t_llx_win *win)
{
	if (!win->is_mouse_outside)
		return ;
	win->is_mouse_outside = 0;
	if (win->on_enter)
		win->on_enter(win);
}

void	llx_on_leave(t_llx_win *win)
{
	if (win->is_mouse_outside)
		return ;
	win->is_mouse_outside = 1;
	if (win->on_leave)
		win->on_leave(win);
}

void	llx_on_close(t_llx_win *win)
{
	if (win->on_close)
		win->on_close(win);
	llx_win_delete(win);
}
