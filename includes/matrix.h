/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:29:54 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/25 14:29:56 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <math.h>

typedef struct s_mat2x2
{
	float	m[4];
}	t_mat2x2;

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

t_mat2x2	mat2x2_rot(float angle);

void		mul_vec2_mat2x2(t_vec2 *vec, t_mat2x2 mat);
void		mul_vec2_f(t_vec2 *vec, float val);

#endif // MATRIX_H
