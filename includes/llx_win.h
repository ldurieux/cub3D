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

# define MAX_KEY_IDX 127

enum e_event
{
	Evt_KeyPress			= 2,
	Evt_KeyRelease			= 3,
	Evt_BtnPress			= 4,
	Evt_BtnRelease			= 5,
	Evt_MotionNotify		= 6,
	Evt_EnterNotify			= 7,
	Evt_LeaveNotify			= 8,
	Evt_FocusIn				= 9,
	Evt_FocusOut			= 10,
	Evt_KeymapNotify		= 11,
	Evt_Expose				= 12,
	Evt_GraphicsExpose		= 13,
	Evt_NoExpose			= 14,
	Evt_VisibilityNotify	= 15,
	Evt_CreateNotify		= 16,
	Evt_DestroyNotify		= 17,
	Evt_UnmapNotify			= 18,
	Evt_MapNotify			= 19,
	Evt_MapRequest			= 20,
	Evt_ReparentNotify		= 21,
	Evt_ConfigureNotify		= 22,
	Evt_ConfigureRequest	= 23,
	Evt_GravityNotify		= 24,
	Evt_ResizeRequest		= 25,
	Evt_CirculateNotify		= 26,
	Evt_CirculateRequest	= 27,
	Evt_PropertyNotify		= 28,
	Evt_SelectionClear		= 29,
	Evt_SelectionRequest	= 30,
	Evt_SelectionNotify		= 31,
	Evt_ColormapNotify		= 32,
	Evt_ClientMessage		= 33,
	Evt_MappingNotify		= 34,
	Evt_GenericEvent		= 35,
	Evt_LASTEvent			= 36,
};

enum e_mask
{
	Msk_NoEvent					= 0x0,
	Msk_KeyPress				= 0x1,
	Msk_KeyRelease				= 0x2,
	Msk_BtnPress				= 0x4,
	Msk_BtnRelease				= 0x8,
	Msk_EnterWindow				= 0x10,
	Msk_LeaveWindow				= 0x20,
	Msk_PointerMotion			= 0x40,
	Msk_PointerMotionHint		= 0x80,
	Msk_Button1Motion			= 0x100,
	Msk_Button2Motion			= 0x200,
	Msk_Button3Motion			= 0x400,
	Msk_Button4Motion			= 0x800,
	Msk_Button5Motion			= 0x1000,
	Msk_ButtonMotion			= 0x2000,
	Msk_KeymapState				= 0x4000,
	Msk_Exposure				= 0x8000,
	Msk_VisibilityChange		= 0x10000,
	Msk_StructureNotify			= 0x20000,
	Msk_ResizeRedirect			= 0x40000,
	Msk_SubstructureNotify		= 0x80000,
	Msk_SubstructureRedirect	= 0x100000,
	Msk_FocusChange				= 0x200000,
	Msk_PropertyChange			= 0x400000,
	Msk_ColormapChange			= 0x800000,
	Msk_OwnerGrabButton			= 0x1000000,
};

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

# endif

typedef struct s_llx		t_llx;
typedef struct s_llx_win	t_llx_win;

typedef struct s_llx_win
{
	void	*mlx_win;
	t_llx	*llx;
	void	*cache;
	void	(*on_key_down)(t_llx_win *win, int keycode);
	void	(*on_key_up)(t_llx_win *win, int keycode);
	void	(*on_mouse_down)(t_llx_win *win, int button, int x, int y);
	void	(*on_mouse_up)(t_llx_win *win, int button, int x, int y);
	void	(*on_mouse_move)(t_llx_win *win, int x, int y);
	void	(*on_enter)(t_llx_win *win);
	void	(*on_leave)(t_llx_win *win);
	void	(*on_close)(t_llx_win *win);
	void	(*on_loop)(t_llx_win *win, void *data);
	int		keys[MAX_KEY_IDX + 1];
	int		width;
	int		height;
	int		last_key_idx;
	uint8_t	id;
}	t_llx_win;

t_llx_win	*llx_win_new(t_llx *llx, int width, int height, char *title);
void		llx_win_delete(t_llx_win *win);
int			llx_win_is_key_down(t_llx_win *win, int key);

#endif // LLX_WIN_H
