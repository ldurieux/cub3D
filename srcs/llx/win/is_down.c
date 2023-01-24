/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:27:05 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 01:27:07 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx_win.h"

int	llx_win_is_key_down(t_llx_win *win, int key)
{
	int	i;

	i = -1;
	while (++i <= win->last_key_idx)
		if (win->keys[i] == key)
			return (1);
	return (0);
}

int	llx_win_is_btn_down(t_llx_win *win, int btn)
{
	int	i;

	i = -1;
	while (++i <= win->last_btn_idx)
		if (win->btns[i] == btn)
			return (1);
	return (0);
}
