/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx_win.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:32:13 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 01:32:15 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_WIN_H
# define LLX_WIN_H

# include <stdint.h>
# include "libft.h"
# include "llx_paint.h"

# define MAX_KEY_IDX 127
# define MAX_BTN_IDX 16

# ifdef __gnu_linux__

enum e_key
{
	LlxKey_A = 97,
	LlxKey_B = 98,
	LlxKey_C = 99,
	LlxKey_D = 100,
	LlxKey_E = 101,
	LlxKey_F = 102,
	LlxKey_G = 103,
	LlxKey_H = 104,
	LlxKey_I = 105,
	LlxKey_J = 106,
	LlxKey_K = 107,
	LlxKey_L = 108,
	LlxKey_M = 109,
	LlxKey_N = 110,
	LlxKey_O = 111,
	LlxKey_P = 112,
	LlxKey_Q = 113,
	LlxKey_R = 114,
	LlxKey_S = 115,
	LlxKey_T = 116,
	LlxKey_U = 117,
	LlxKey_V = 118,
	LlxKey_W = 119,
	LlxKey_X = 120,
	LlxKey_Y = 121,
	LlxKey_Z = 122,
	LlxKey_Left		= 65361,
	LlxKey_Up		= 65362,
	LlxKey_Right	= 65363,
	LlxKey_Down		= 65364,
	LlxKey_Plus		= 65451,
	LlxKey_Minus	= 65453,
	LlxKey_0 = 224,
	LlxKey_1 = 38,
	LlxKey_2 = 233,
	LlxKey_3 = 34,
	LlxKey_4 = 39,
	LlxKey_5 = 40,
	LlxKey_6 = 45,
	LlxKey_7 = 232,
	LlxKey_8 = 95,
	LlxKey_9 = 231,
	LlxKey_Escape = 65307,
};

enum e_btn {
	LlxBtn_Left = 1,
	LlxBtn_Right = 2,
	LlxBtn_Middle = 3,
	LlxBtn_WheelUp = 4,
	LlxBtn_WheelDown = 5,
};
# else

enum e_key {
	LlxKey_A = 0,
	LlxKey_B = 11,
	LlxKey_C = 8,
	LlxKey_D = 2,
	LlxKey_E = 14,
	LlxKey_F = 3,
	LlxKey_G = 5,
	LlxKey_H = 4,
	LlxKey_I = 34,
	LlxKey_J = 38,
	LlxKey_K = 40,
	LlxKey_L = 37,
	LlxKey_M = 46,
	LlxKey_N = 45,
	LlxKey_O = 31,
	LlxKey_P = 35,
	LlxKey_Q = 12,
	LlxKey_R = 15,
	LlxKey_S = 1,
	LlxKey_T = 17,
	LlxKey_U = 32,
	LlxKey_V = 9,
	LlxKey_W = 13,
	LlxKey_X = 7,
	LlxKey_Y = 16,
	LlxKey_Z = 6,
	LlxKey_Left = 123,
	LlxKey_Up = 126,
	LlxKey_Right = 124,
	LlxKey_Down = 125,
	LlxKey_Plus = 69,
	LlxKey_Minus = 78,
	LlxKey_0 = 29,
	LlxKey_1 = 18,
	LlxKey_2 = 19,
	LlxKey_3 = 20,
	LlxKey_4 = 21,
	LlxKey_5 = 23,
	LlxKey_6 = 22,
	LlxKey_7 = 26,
	LlxKey_8 = 28,
	LlxKey_9 = 25,
	LlxKey_Escape = 53,
};

enum e_btn {
	LlxBtn_Left = 1,
	LlxBtn_Right = 2,
	LlxBtn_Middle = 3,
	LlxBtn_WheelUp = 4,
	LlxBtn_WheelDown = 5,
};

# endif

typedef struct s_llx		t_llx;
typedef struct s_llx_win	t_llx_win;

/**
 * @brief contains information on a window
 *
 * each function pointer may be set by the user
 */
typedef struct s_llx_win
{
	void	*mlx_win;
	t_llx	*llx;
	void	*cache;
	void	(*on_key_down)(t_llx_win *win, int keycode);
	void	(*on_key_up)(t_llx_win *win, int keycode);
	void	(*on_mouse_down)(t_llx_win *win, int button, t_point pos);
	void	(*on_mouse_up)(t_llx_win *win, int button, t_point pos);
	void	(*on_mouse_move)(t_llx_win *win, t_point pos);
	void	(*on_enter)(t_llx_win *win);
	void	(*on_leave)(t_llx_win *win);
	void	(*on_close)(t_llx_win *win);
	void	(*on_loop)(t_llx_win *win, void *data);
	int		keys[MAX_KEY_IDX + 1];
	int		btns[MAX_BTN_IDX + 1];
	t_point	mouse_pos;
	int		width;
	int		height;
	int		last_key_idx;
	int		last_btn_idx;
	uint8_t	is_mouse_outside;
	uint8_t	id;
}	t_llx_win;

/**
 * @brief instantiate a new window, the return value MUST NOT be stored
 * outside of the function call scope as the address may change later
 * @param llx pointer
 * @param window width
 * @param window height
 * @param window title
 * @return pointer to the window, NULL if an error occured
 */
t_llx_win	*llx_win_new(t_llx *llx, int width, int height, char *title);

/**
 * @brief close and free a window, this function does not trigger
 * llx_win.on_close
 * @param window ptr
 */
void		llx_win_delete(t_llx_win *win);

/**
 * @brief check if a key is being held down
 * @param window ptr
 * @param key
 * @return 0 if the key is NOT down
 */
int			llx_win_is_key_down(t_llx_win *win, int key);

/**
 * @brief check if a button is being held down
 * @param window ptr
 * @param button
 * @return 0 if the button is NOT down
 */
int			llx_win_is_btn_down(t_llx_win *win, int btn);

/**
 * @brief get the pixel array of the window
 * @param window ptr
 * @return 0 if an error occured
 */
uint32_t	*llx_win_cache(t_llx_win *win);

#endif // LLX_WIN_H
