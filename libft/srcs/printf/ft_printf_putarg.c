/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putarg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:26:37 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/21 13:26:38 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_printf_putarg(int fd, t_printf_conversion conv, t_printf_arg arg)
{
	if (conv.conv & C_Int && conv.conv & C_Unsigned)
		return (ft_printf_putuint(fd, conv, arg.u));
	if (conv.conv & C_Int)
		return (ft_printf_putint(fd, conv, arg.i));
	if (conv.conv & C_Char)
		return (ft_printf_putchar(fd, conv, arg.c));
	if (conv.conv & C_String)
		return (ft_printf_putstr(fd, conv, arg.s));
	if (conv.conv & C_Pointer)
	{
		conv = (t_printf_conversion)
		{conv.width, -1, conv.flags | F_Alternate, 0,
			C_Int | C_Pointer | C_Hexa | C_Unsigned};
		return (ft_printf_putptr(fd, conv, (uint64_t)arg.p));
	}
	if (conv.conv & C_Percent)
		return ((int)write(fd, "%", 1));
	return (-1);
}
