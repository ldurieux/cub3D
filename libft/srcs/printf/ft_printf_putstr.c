/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:01:47 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/10 17:01:48 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	ft_printf_putstr(int fd, t_printf_conversion conv, char *str)
{
	size_t	size;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (conv.precision != -1)
		if (conv.precision < (int)str_len)
			str_len = (size_t)conv.precision;
	size = 0;
	if (conv.width > 0)
		size = (size_t)conv.width;
	if (size <= str_len)
		size = 0;
	else
		size -= str_len;
	if (!(conv.flags & F_Left_Adjusted))
		ft_printf_putalign(fd, (int)size, ' ');
	write(fd, str, str_len);
	if (conv.flags & F_Left_Adjusted)
		ft_printf_putalign(fd, (int)size, ' ');
	return ((int)(size + str_len));
}
