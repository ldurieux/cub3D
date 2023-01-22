/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getarg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:07:21 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/20 16:07:22 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static t_printf_arg	ft_getint(t_printf_conversion conv, va_list args)
{
	t_printf_arg	res;

	if (conv.length_mod & L_Int_Min)
		res.i = (int64_t)(char)va_arg(args, int);
	else if (conv.length_mod & L_Int_Small)
		res.i = (short)va_arg(args, int);
	else if (conv.length_mod & L_Int_Long)
		res.i = (long)va_arg(args, long);
	else if (conv.length_mod & L_Int_LongLong)
		res.i = (long long)va_arg(args, long long);
	else if (conv.length_mod & L_Int_Max)
		res.i = (intmax_t)va_arg(args, intmax_t);
	else if (conv.length_mod & L_Int_Size)
		res.i = (int64_t)va_arg(args, size_t);
	else if (conv.length_mod & L_Ptrdiff)
		res.i = va_arg(args, ptrdiff_t);
	else
		res.i = va_arg(args, int);
	return (res);
}

static t_printf_arg	ft_getuint(t_printf_conversion conv, va_list args)
{
	t_printf_arg	res;

	if (conv.length_mod & L_Int_Min)
		res.u = (unsigned char)va_arg(args, unsigned int);
	else if (conv.length_mod & L_Int_Small)
		res.u = (unsigned short)va_arg(args, unsigned int);
	else if (conv.length_mod & L_Int_Long)
		res.u = (unsigned long)va_arg(args, unsigned long);
	else if (conv.length_mod & L_Int_LongLong)
		res.u = (unsigned long long)va_arg(args, unsigned long long);
	else if (conv.length_mod & L_Int_Max)
		res.u = (uintmax_t)va_arg(args, uintmax_t);
	else if (conv.length_mod & L_Int_Size)
		res.u = va_arg(args, size_t);
	else if (conv.length_mod & L_Ptrdiff)
		res.u = (uint64_t)va_arg(args, ptrdiff_t);
	else
		res.u = va_arg(args, unsigned int);
	return (res);
}

static t_printf_arg	ft_getdouble(t_printf_conversion conv, va_list args)
{
	t_printf_arg	res;

	if (conv.length_mod & L_Double_Long)
		res.lf = va_arg(args, long double);
	else
		res.f = va_arg(args, double);
	return (res);
}

t_printf_arg	ft_printf_getarg(t_printf_conversion conv, va_list args)
{
	t_printf_arg	res;

	if (conv.conv & C_Int && !(conv.conv & C_Unsigned))
		res = ft_getint(conv, args);
	else if (conv.conv & C_Int)
		res = ft_getuint(conv, args);
	else if (conv.conv & C_Double)
		res = ft_getdouble(conv, args);
	else if (conv.conv & C_Char)
		res.i = va_arg(args, int);
	else if (conv.conv & C_String)
	{
		res.s = va_arg(args, char *);
		if (!res.s)
			res.s = "(null)";
	}
	else if ((conv.conv & C_Pointer) || (conv.conv & C_Get_Written))
		res.p = va_arg(args, void *);
	else if (conv.conv & C_Percent)
		res.c = '%';
	else
		res.i = 0;
	return (res);
}
