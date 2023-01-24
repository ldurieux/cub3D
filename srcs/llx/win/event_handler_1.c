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
	if (win->last_key_idx < MAX_KEY_IDX && !llx_win_is_key_down(win, keycode))
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
	if (win->last_btn_idx < MAX_BTN_IDX && !llx_win_is_btn_down(win, button)
		&& button != LlxBtn_WheelUp && button != LlxBtn_WheelDown)
	{
		win->last_btn_idx++;
		win->btns[win->last_btn_idx] = button;
	}
	if (win->on_mouse_down)
		win->on_mouse_down(win, button, point(x, y));
}

void	llx_on_mouse_up(int button, int x, int y, t_llx_win *win)
{
	int	btn_idx;

	btn_idx = -1;
	while (++btn_idx <= win->last_btn_idx)
		if (win->btns[btn_idx] == button)
			break ;
	if (btn_idx <= win->last_btn_idx)
	{
		win->btns[btn_idx] = win->btns[win->last_btn_idx];
		win->last_btn_idx--;
	}
	if (win->on_mouse_up)
		win->on_mouse_up(win, button, point(x, y));
}

void	llx_on_mouse_move(int x, int y, t_llx_win *win)
{
	win->mouse_pos = point(x, y);
	if (win->on_mouse_move)
		win->on_mouse_move(win, win->mouse_pos);
	if (win->is_mouse_outside
		&& x >= 0 && y >= 0 && x < win->width && y < win->height)
		llx_on_enter(win);
	if (!win->is_mouse_outside
		&& (x < 0 || y < 0 || x >= win->width || y >= win->height))
		llx_on_leave(win);
}
