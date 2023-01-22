/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:07:34 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/20 14:07:35 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internal.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vprintf(format, args);
	va_end(args);
	return (res);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vdprintf(fd, format, args);
	va_end(args);
	return (res);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vsprintf(str, format, args);
	va_end(args);
	return (res);
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vsnprintf(str, size, format, args);
	va_end(args);
	return (res);
}
