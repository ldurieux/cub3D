/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx_paint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:24:28 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 08:24:29 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_PAINT_H
# define LLX_PAINT_H

# include <stdlib.h>
# include <stdint.h>
# include <math.h>

enum e_color
{
	Llx_Transparent	= 0xff000000,
	Llx_White		= 0x00ffffff,
	Llx_Black		= 0x00000000,
	Llx_Red			= 0x00ff0000,
	Llx_Green		= 0x0000ff00,
	Llx_Blue		= 0x000000ff,
	Llx_Yellow		= Llx_Red | Llx_Green,
	Llx_Magenta		= Llx_Red | Llx_Blue,
	Llx_Cyan		= Llx_Green | Llx_Blue,
};

typedef struct s_point
{
	int16_t	x;
	int16_t	y;
}	t_point;

typedef struct s_rect
{
	int16_t	x;
	int16_t	y;
	int16_t	w;
	int16_t	h;
}	t_rect;

typedef struct s_bounds
{
	int16_t	x1;
	int16_t	y1;
	int16_t	x2;
	int16_t	y2;
}	t_bounds;

typedef struct s_rgba
{
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;
	uint8_t	a;
}	t_rgba;

typedef union u_color
{
	uint32_t	ucolor;
	int32_t		color;
	t_rgba		rgba;
}	t_color;

typedef struct s_img
{
	void		*addr;
	uint32_t	*data;
	int			width;
	int			height;
}	t_img;

typedef struct s_llx_win	t_llx_win;

/**
 * @brief this is an helper struct for drawing
 *
 * if bounds is set as follow: (t_bounds){point(10, 10), point(20, 20)},
 * calling paint_pixel(point(0, 0)) will draw on point(10, 10)
 * calling paint_pixel(point(10, 10)) will draw on point(20, 20)
 * calling paint_pixel(point(11, 11)) will not draw anything
 */
typedef struct s_paint
{
	t_llx_win	*win;
	uint32_t	*data;
	uint32_t	width;
	t_color		pen;
	t_bounds	bounds;
}	t_paint;

/**
 * @brief initialize a paint struct
 * @param paint
 * @param window to paint on
 * @return 0 if an error occured
 */
int			paint_init(t_paint *paint, t_llx_win *win);

/**
 * @brief set bounds of paint, if bounds is outside the window clip it
 * @param paint
 * @param bounds
 * @return paint parameter
 */
t_paint		*paint_set_bounds(t_paint *paint, t_bounds bounds);
t_paint		*paint_reset_bounds(t_paint *paint);

/**
 * @brief set color of paint, this is an utility function as the same can be
 * done by setting paint->pen
 * @param paint
 * @param pen
 * @return paint parameter
 */
t_paint		*paint_set_color(t_paint *paint, t_color pen);

/**
 * @brief draw a pixel. This function is slow only use it if you need a paint
 * struct
 * @param paint
 * @param point
 */
void		paint_pixel(t_paint *paint, t_point p);
void		paint_line(t_paint *paint, t_point p1, t_point p2);
void		paint_rect(t_paint *paint, t_rect rect);
void		paint_fill(t_paint *paint);

t_point		point(int16_t x, int16_t y);
t_rect		rect(t_point p, int16_t w, int16_t h);
t_bounds	bounds(t_point p1, t_point p2);
t_color		color(uint32_t color);

#endif // LLX_PAINT_H
