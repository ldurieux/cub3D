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

void	cub_on_key(t_cub *cub, t_llx_win *win)
{
	(void)cub;
	if (llx_win_is_key_down(win, LlxKey_Escape))
		llx_exit(win->llx, 0);
}
