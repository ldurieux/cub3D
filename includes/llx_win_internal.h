/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx_win_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:38:51 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 01:38:53 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_WIN_INTERNAL_H
# define LLX_WIN_INTERNAL_H

typedef struct s_llx_win	t_llx_win;

void	llx_on_key_down(int keycode, t_llx_win *win);
void	llx_on_key_up(int keycode, t_llx_win *win);
void	llx_on_mouse_down(int button, int x, int y, t_llx_win *win);
void	llx_on_mouse_up(int button, int x, int y, t_llx_win *win);
void	llx_on_mouse_move(int x, int y, t_llx_win *win);
void	llx_on_enter(t_llx_win *win);
void	llx_on_leave(t_llx_win *win);
void	llx_on_close(t_llx_win *win);

#endif // LLX_WIN_INTERNAL_H
