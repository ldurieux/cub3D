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

typedef struct s_img_data
{
	int	line_bytes;
	int	pixel_bits;
	int	endian;
}	t_img_data;

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
