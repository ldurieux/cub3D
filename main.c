/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:50:28 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/23 16:50:29 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "llx.h"
#include "llx_win.h"
#include "llx_paint.h"
#include "ft_printf.h"

void	on_loop(t_llx_win *win, void *map_ptr)
{
	t_map			*map;
	t_paint			p;
	const int16_t	h_2 = (win->height - 1) >> 1;

	map = map_ptr;
	paint_init(&p, win);
	p.pen = (t_color)map->colors[CEIL];
	paint_rect(&p, rect(point(0, 0), win->width, h_2));
	p.pen = (t_color)map->colors[FLOOR];
	paint_rect(&p, rect(point(0, h_2), win->width, h_2));
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_llx		llx;
	t_llx_win	*win;

	if (argc != 2)
		return (ft_dprintf(2, "Error\nInvalid arguments count\n"), 0);
	if (!llx_init(&llx))
		return (ft_dprintf(2, "Error\nCouldn't start llx\n"));
	if (!map_load(&map, argv[1], llx.mlx))
		return (llx_destroy(&llx), map_free(&map), 1);
	win = llx_win_new(&llx, 1366, 768, "cub3D");
	if (!win)
		return (llx_destroy(&llx), map_free(&map), 1);
	llx.data = &map;
	win->on_loop = on_loop;
	return (llx_exec(&llx));
}
