/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:29:53 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/25 14:29:54 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	mul_vec2_mat2x2(t_vec2 *vec, t_mat2x2 mat)
{
	t_vec2	tmp;
	float	*m;

	m = mat.m;
	tmp.x = vec->x * m[0] + vec->y * m[1];
	tmp.y = vec->x * m[2] + vec->y * m[3];
	*vec = tmp;
}

void	mul_vec2_f(t_vec2 *vec, float val)
{
	vec->x *= val;
	vec->y *= val;
}
