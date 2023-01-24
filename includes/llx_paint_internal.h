/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx_paint_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:24:30 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 08:24:31 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_PAINT_INTERNAL_H
# define LLX_PAINT_INTERNAL_H

# include "mlx.h"

typedef struct s_paint	t_paint;
typedef struct s_point	t_point;

typedef struct s_img_data
{
	int	line_bytes;
	int	pixel_bits;
	int	endian;
}	t_img_data;

int	is_in_bound(t_paint *paint, t_point p);

#endif // LLX_PAINT_INTERNAL_H
