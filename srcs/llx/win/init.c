/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:26:58 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 01:27:01 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_win.h"
#include "llx_win_internal.h"
#include "llx.h"

static void	connect_win(t_llx_win *w)
{
	void	*m;

	m = w->mlx_win;
	mlx_hook(m, Evt_KeyPress, Msk_KeyPress, (void *) llx_on_key_down, w);
	mlx_hook(m, Evt_KeyRelease, Msk_KeyRelease, (void *) llx_on_key_up, w);
	mlx_hook(m, Evt_BtnPress, Msk_BtnPress, (void *) llx_on_mouse_down, w);
	mlx_hook(m, Evt_BtnRelease, Msk_BtnRelease, (void *) llx_on_mouse_up, w);
	mlx_hook(m, Evt_MotionNotify, Msk_NoEvent, (void *) llx_on_mouse_move, w);
	mlx_hook(m, Evt_EnterNotify, Msk_EnterWindow, (void *) llx_on_enter, w);
	mlx_hook(m, Evt_LeaveNotify, Msk_LeaveWindow, (void *) llx_on_leave, w);
	mlx_hook(m, Evt_DestroyNotify, Msk_NoEvent, (void *) llx_on_close, w);
}

#define MIN_WIDTH 10
#define MIN_HEIGHT 10

t_llx_win	*llx_win_new(t_llx *llx, int width, int height, char *title)
{
	t_llx_win	*win;

	if (!llx || width < MIN_WIDTH || height < MIN_HEIGHT || !title
		|| llx->last_win_id >= LLX_MAX_WIN)
		return (NULL);
	win = llx->windows + llx->last_win_id;
	ft_memset(win, 0, sizeof(t_llx_win));
	win->llx = llx;
	win->id = llx->last_win_id;
	win->width = width;
	win->height = height;
	win->last_key_idx = -1;
	win->last_btn_idx = -1;
	win->cache = mlx_new_image(llx->mlx, width, height);
	win->mlx_win = mlx_new_window(llx->mlx, width, height, title);
	if (!win->mlx_win || !win->cache)
		return (llx_win_delete(win), NULL);
	llx->last_win_id++;
	llx->win_count++;
	connect_win(win);
	return (win);
}

void	llx_win_delete(t_llx_win *win)
{
	uint8_t	last_id;
	t_llx	*llx;

	if (!win)
		return ;
	llx = win->llx;
	if (llx->windows + win->id == win)
	{
		llx->win_count--;
		last_id = --llx->last_win_id;
		llx->windows[last_id].id = win->id;
		ft_swap(llx->windows + win->id, llx->windows + last_id,
			sizeof(t_llx_win));
		connect_win(llx->windows + win->id);
		win = llx->windows + last_id;
	}
	if (win->mlx_win)
		mlx_destroy_window(llx->mlx, win->mlx_win);
	if (win->cache)
		mlx_destroy_image(llx->mlx, win->cache);
	if (llx->win_count == 0)
		llx_exit(llx, 0);
	ft_memset(win, 0, sizeof(t_llx_win));
}

uint32_t	*llx_win_cache(t_llx_win *win)
{
	t_img_data	data;
	uint32_t	*res;

	if (!win)
		return (NULL);
	res = (uint32_t *)mlx_get_data_addr(win->cache, &data.pixel_bits,
			&data.line_bytes, &data.endian);
	return (res);
}
