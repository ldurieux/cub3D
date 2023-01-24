/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:25:37 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/23 19:25:38 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx.h"
#include "llx_win.h"

void	llx_destroy(t_llx *llx)
{
	size_t	i;

	i = (size_t) - 1;
	if (llx->windows)
	{
		while (++i < llx->win_count)
		{
			if (llx->windows[i].on_close)
				llx->windows[i].on_close(llx->windows + i);
			llx_win_delete(llx->windows + i);
		}
	}
	free(llx->windows);
	llx->windows = NULL;
	llx->last_win_id = 0;
	llx->win_count = 0;
}

static void	llx_on_exit(t_llx *llx)
{
	int	exit_code;

	exit_code = llx->exit_code;
	if (llx->on_exit)
		llx->on_exit(llx);
	llx_destroy(llx);
	exit(exit_code);
}

static int	llx_on_loop(t_llx *llx)
{
	size_t		i;
	t_llx_win	*win;

	if (llx->exit_code != -1)
		return (llx_on_exit(llx), 0);
	i = (size_t)-1;
	while (++i < llx->win_count)
	{
		win = llx->windows + i;
		if (win->on_loop)
			win->on_loop(win, llx->data);
		mlx_put_image_to_window(llx->mlx, win->mlx_win, win->cache, 0, 0);
	}
	return (0);
}

int	llx_init(t_llx *llx)
{
	if (!llx)
		return (0);
	ft_memset(llx, 0, sizeof(t_llx));
	llx->exit_code = -1;
	llx->mlx = mlx_init();
	llx->windows = ft_calloc(sizeof(t_llx_win), LLX_MAX_WIN);
	if (!llx->mlx || !llx->windows)
	{
		llx_destroy(llx);
		return (0);
	}
	mlx_loop_hook(llx->mlx, llx_on_loop, llx);
	return (1);
}
