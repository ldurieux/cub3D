/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:07:36 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/20 14:07:37 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	ft_get_flags(char **format, t_printf_conversion *conv)
{
	uint8_t	res;

	res = 0;
	while (ft_strpbrk(*format, "#0- +") == *format)
	{
		res |= (**format == '#') * F_Alternate;
		res |= (**format == '0') * F_Zero_Padded;
		res |= (**format == '-') * F_Left_Adjusted;
		res |= (**format == ' ') * F_Space_Prefixed;
		res |= (**format == '+') * F_Force_Sign;
		(*format)++;
	}
	conv->flags = res;
}

static void	ft_get_width_and_precision(char **format,
				t_printf_conversion *conv, va_list args)
{
	if (**format == '*')
	{
		conv->width = va_arg(args, int);
		(*format)++;
	}
	else if ((**format) >= '0' && (**format) <= '9')
		conv->width = ft_strtoi(*format, format);
	else
		conv->width = 0;
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			conv->precision = va_arg(args, int);
			(*format)++;
		}
		else if ((**format) >= '0' && (**format) <= '9')
			conv->precision = ft_strtoi(*format, format);
		else
			conv->precision = 0;
	}
	else
		conv->precision = -1;
}

static void	ft_get_length_modifier(char **format,
				t_printf_conversion *conv)
{
	uint8_t		res;
	ptrdiff_t	len;

	res = 0;
	len = (ft_strpbrk(*format, "hlLjzt") - *format) + 1;
	if (**format == 'l' || **format == 'h')
		if (*(*format + 1) == **format)
			len++;
	if (len == 1)
	{
		res |= (**format == 'h') * L_Int_Small;
		res |= (**format == 'l') * L_Int_Long;
		res |= (**format == 'L') * L_Double_Long;
		res |= (**format == 'j') * L_Int_Max;
		res |= (**format == 'z') * L_Int_Size;
		res |= (**format == 't') * L_Ptrdiff;
		(*format)++;
	}
	else if (len == 2)
	{
		res |= (ft_strncmp(*format, "hh", 2) == 0) * L_Int_Min;
		res |= (ft_strncmp(*format, "ll", 2) == 0) * L_Int_LongLong;
		(*format) += (ptrdiff_t)((res != 0) * 2);
	}
	conv->length_mod = res;
}

static void	ft_get_conversion(char **f, t_printf_conversion *conv)
{
	conv->conv = 0;
	if (ft_strpbrk(*f, "diouxXeEfFgGaAcspn%") != *f)
		return ;
	conv->conv |= ((**f == 'd') || (**f == 'i')) * (C_Int | C_Decimal);
	conv->conv |= (**f == 'o') * (C_Int | C_Octal | C_Unsigned);
	conv->conv |= (**f == 'u') * (C_Int | C_Decimal | C_Unsigned);
	conv->conv |= (**f == 'x') * (C_Int | C_Hexa | C_Unsigned);
	conv->conv |= (**f == 'X') * (C_Int | C_Hexa | C_Upper | C_Unsigned);
	conv->conv |= (**f == 'e') * (C_Double | C_Scientific);
	conv->conv |= (**f == 'E') * (C_Double | C_Scientific | C_Upper);
	conv->conv |= (**f == 'f') * (C_Double | C_Decimal);
	conv->conv |= (**f == 'F') * (C_Double | C_Decimal | C_Upper);
	conv->conv |= (**f == 'g') * (C_Double | C_Smallest);
	conv->conv |= (**f == 'G') * (C_Double | C_Smallest | C_Upper);
	conv->conv |= (**f == 'a') * (C_Double | C_Hexa);
	conv->conv |= (**f == 'A') * (C_Double | C_Hexa | C_Upper);
	conv->conv |= (**f == 'c') * (C_Char);
	conv->conv |= (**f == 's') * (C_String);
	conv->conv |= (**f == 'p') * (C_Pointer | C_Unsigned);
	conv->conv |= (**f == 'n') * (C_Get_Written);
	conv->conv |= (**f == '%') * (C_Percent);
	(*f)++;
}

t_printf_conversion	ft_printf_parse_conversion(char **format, va_list args)
{
	t_printf_conversion	res;

	ft_get_flags(format, &res);
	ft_get_width_and_precision(format, &res, args);
	ft_get_length_modifier(format, &res);
	ft_get_conversion(format, &res);
	ft_printf_sanitize(&res);
	return (res);
}
