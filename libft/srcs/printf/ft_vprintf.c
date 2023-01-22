/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:07:38 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/20 14:07:44 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internal.h"

int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(STDOUT_FILENO, format, ap));
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_printf_conversion	conv;
	t_printf_arg		arg;
	int					res;

	res = 0;
	while (*format)
	{
		while (*format != '%' && *format)
		{
			write(fd, format++, 1);
			res++;
		}
		if (!*format)
			break ;
		format++;
		conv = ft_printf_parse_conversion((char **)&format, ap);
		arg = ft_printf_getarg(conv, ap);
		if (conv.conv & C_Get_Written)
			ft_printf_getwritten(res, conv, arg);
		else
			res += ft_printf_putarg(fd, conv, arg);
	}
	return (res);
}

//NOLINTBEGIN
int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	(void)str;
	(void)format;
	(void)ap;
	return (-1);
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	(void)str;
	(void)size;
	(void)format;
	(void)ap;
	return (-1);
}
//NOLINTEND
