/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:51:58 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/25 02:52:00 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cub_init(t_cub *cub, char *file, void *mlx)
{
	ft_memset(cub, 0, sizeof(t_cub));
	if (!map_load(&cub->map, file, mlx))
		return (0);
	cub->player.x = cub->map.spawn.x + 0.5f;
	cub->player.y = cub->map.spawn.y + 0.5f;
	cub->player.dir = cub->map.spawn.dir * M_PI_2;
	cub->mm_bounds.x1 = 25;
	cub->mm_bounds.y1 = 25;
	cub->mm_bounds.x2 = 225;
	cub->mm_bounds.y2 = 225;
	return (1);
}

void	cub_free(t_cub *cub)
{
	if (!cub)
		return ;
	map_free(&cub->map);
}
