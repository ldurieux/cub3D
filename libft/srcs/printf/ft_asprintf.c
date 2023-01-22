/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:07:31 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/20 14:07:32 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internal.h"

int	ft_asprintf(char **strp, const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vasprintf(strp, format, args);
	va_end(args);
	return (res);
}

//TODO
//aproximate length
int	ft_vasprintf(char **strp, const char *format, va_list ap)
{
	int	length;

	length = 0;
	*strp = malloc(sizeof(char) * (uint64_t)(length + 1));
	if (!*strp)
		return (-1);
	return (ft_vsprintf(*strp, format, ap));
}
