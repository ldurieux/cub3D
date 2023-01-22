/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:01:41 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/10 17:01:42 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_printf_putptr(int fd, t_printf_conversion conv, uint64_t val)
{
	char	*number;
	size_t	number_len;
	size_t	res_len;

	res_len = 0;
	number = ft_printf_ulltoa(val, conv, "0123456789abcdef", &number_len);
	conv.width -= 2;
	if (!(conv.flags & F_Left_Adjusted))
		res_len += ft_printf_putalign(fd, conv.width - (int)number_len, ' ');
	res_len += (size_t)write(fd, "0x", 2);
	res_len += (size_t)write(fd, number, number_len);
	if (conv.flags & F_Left_Adjusted)
		res_len += ft_printf_putalign(fd, conv.width - (int)number_len, ' ');
	free(number);
	return ((int)(res_len));
}
