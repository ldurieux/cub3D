/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:50:28 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/27 16:23:34 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ft_printf.h"
#include <stdio.h>

static void	on_loop(t_llx_win *win, void *map_ptr)
{
	t_cub		*cub;
	t_paint		p;

	cub = map_ptr;
	cub_on_key(cub, win);
	cub_on_mouse(cub, win);
	paint_init(&p, win);
	cub_draw_background(cub, &p);
	cub_draw_game(cub, &p);
	paint_set_bounds(&p, cub->mm_bounds);
	cub_draw_minimap(cub, &p);
}

static void	cub_on_exit(t_llx *llx)
{
	t_cub	*cub;

	cub = llx->data;
	cub_free(cub);
}

int	main(int argc, char **argv)
{
	t_cub		cub;
	t_llx		llx;
	t_llx_win	*win;

	if (argc != 2)
		return (ft_dprintf(2, "Error\nInvalid arguments count\n"), 0);
	if (!llx_init(&llx))
		return (ft_dprintf(2, "Error\nCouldn't start llx\n"));
	if (!cub_init(&cub, argv[1], llx.mlx))
		return (llx_destroy(&llx), cub_free(&cub), 1);
	win = llx_win_new(&llx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!win)
		return (llx_destroy(&llx), cub_free(&cub), 1);
	llx.data = &cub;
	llx.on_exit = cub_on_exit;
	win->on_loop = on_loop;
	return (llx_exec(&llx));
}
