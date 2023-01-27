/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:04:16 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/25 03:04:17 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define HALF_SQRT 0.70710678118f

static void	rotate(t_cub *cub, t_llx_win *win)
{
	cub->player.dir += llx_win_is_key_down(win, LlxKey_Left) * ROT_SPEED;
	cub->player.dir -= llx_win_is_key_down(win, LlxKey_Right) * ROT_SPEED;
	if (cub->player.dir > M_PI * 2)
		cub->player.dir -= M_PI * 2;
	if (cub->player.dir < 0)
		cub->player.dir += M_PI * 2;
}

static void	set_pos(t_map *map, t_player *player, t_vec2 move)
{
	uint8_t	dest;

	move.x += player->x;
	move.y += player->y;
	if ((int)move.x != (int)player->x || (int)move.y != (int)player->y)
	{
		if ((int)move.x != (int)player->x && (int)move.y != (int)player->y)
		{
			dest = map->data[((int)move.y) * map->width + (int)player->x];
			if (dest == WALL || dest == 0 || dest == CLOSED_DOOR)
				return ;
			dest = map->data[((int)player->y) * map->width + (int)move.x];
			if (dest == WALL || dest == 0 || dest == CLOSED_DOOR)
				return ;
		}
		dest = map->data[(int)move.y * map->width + (int)move.x];
		if (dest == WALL || dest == 0 || dest == CLOSED_DOOR)
			return ;
	}
	player->x = move.x;
	player->y = move.y;
}

static void	translate(t_cub *cub, t_llx_win *win)
{
	t_vec2		move;
	t_mat2x2	mat_rot;

	move.x = llx_win_is_key_down(win, LlxKey_W);
	move.y = llx_win_is_key_down(win, LlxKey_D);
	move.x -= llx_win_is_key_down(win, LlxKey_S);
	move.y -= llx_win_is_key_down(win, LlxKey_A);
	if (fabs(move.x) > 0.1f && fabs(move.y) > 0.1f)
		mul_vec2_f(&move, HALF_SQRT);
	mat_rot = mat2x2_rot(cub->player.dir);
	mul_vec2_mat2x2(&move, mat_rot);
	mul_vec2_f(&move, MOVE_SPEED);
	set_pos(&cub->map, &cub->player, move);
}

void	cub_on_key(t_cub *cub, t_llx_win *win)
{
	rotate(cub, win);
	translate(cub, win);
	if (llx_win_is_key_down(win, LlxKey_Escape))
		llx_exit(win->llx, 0);
}
