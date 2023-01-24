/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:38:33 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 01:38:35 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_win.h"
#include "llx_win_internal.h"

void	llx_on_key_down(int keycode, t_llx_win *win)
{
	if (win->last_key_idx < MAX_KEY_IDX
		&& !llx_win_is_key_down(win, keycode))
	{
		win->last_key_idx++;
		win->keys[win->last_key_idx] = keycode;
	}
	if (win->on_key_down)
		win->on_key_down(win, keycode);
}

void	llx_on_key_up(int keycode, t_llx_win *win)
{
	int	key_idx;

	key_idx = -1;
	while (++key_idx <= win->last_key_idx)
		if (win->keys[key_idx] == keycode)
			break ;
	if (key_idx <= win->last_key_idx)
	{
		win->keys[key_idx] = win->keys[win->last_key_idx];
		win->last_key_idx--;
	}
	if (win->on_key_up)
		win->on_key_up(win, keycode);
}

void	llx_on_mouse_down(int button, int x, int y, t_llx_win *win)
{
	if (win->on_mouse_down)
		win->on_mouse_down(win, button, x, y);
}

void	llx_on_mouse_up(int button, int x, int y, t_llx_win *win)
{
	if (win->on_mouse_up)
		win->on_mouse_up(win, button, x, y);
}

void	llx_on_mouse_move(int x, int y, t_llx_win *win)
{
	if (win->on_mouse_move)
		win->on_mouse_move(win, x, y);
}
