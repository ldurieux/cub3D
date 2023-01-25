/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:29:50 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/25 14:29:52 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat2x2	mat2x2_rot(float angle)
{
	const float	c = cosf(angle);
	const float	s = sinf(angle);
	t_mat2x2	res;

	res.m[0] = c;
	res.m[1] = s;
	res.m[2] = -s;
	res.m[3] = c;
	return (res);
}
