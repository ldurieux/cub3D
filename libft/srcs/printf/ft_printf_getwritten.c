/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getwritten.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:47:13 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/22 13:47:14 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

typedef union u_cast
{
	int64_t	lld;
	int32_t	d;
	int16_t	hd;
	int8_t	hhd;
}	t_cast;

void	ft_printf_getwritten(int written, t_printf_conversion conv,
						t_printf_arg arg)
{
	t_cast	cast;

	cast.d = written;
	if (conv.length_mod & L_Int_Min)
		*((int8_t *)arg.p) = cast.hhd;
	else if (conv.length_mod & L_Int_Small)
		*((int16_t *)arg.p) = cast.hd;
	else if (conv.length_mod & L_Int_Long
		|| conv.length_mod & L_Int_LongLong
		|| conv.length_mod & L_Int_Max
		|| conv.length_mod & L_Int_Size
		|| conv.length_mod & L_Ptrdiff)
		*((int64_t *)arg.p) = cast.lld;
	else
		*((int32_t *)arg.p) = cast.d;
}
