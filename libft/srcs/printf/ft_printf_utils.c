/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:27:32 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/22 16:27:33 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

char	*ft_printf_base(t_printf_conversion conv)
{
	if (conv.conv & C_Decimal)
		return ("0123456789");
	if (conv.conv & C_Octal)
		return ("01234567");
	if (conv.conv & C_Hexa && !(conv.conv & C_Upper))
		return ("0123456789abcdef");
	if (conv.conv & C_Hexa)
		return ("0123456789ABCDEF");
	return (NULL);
}

int	ft_printf_setalter(uint64_t val, const char *number,
						int number_len, t_printf_conversion *conv)
{
	if ((conv->conv & C_Octal && (number[0] == '0'
				|| conv->precision < number_len))
		|| (conv->conv & C_Hexa && (val == 0)))
		conv->flags &= ~F_Alternate;
	if (conv->flags & F_Alternate)
	{
		if (conv->conv & C_Octal)
			return (1);
		if (conv->conv & C_Hexa)
			return (2);
	}
	return (0);
}

size_t	ft_printf_putalign(int fd, int len, char chr)
{
	int	i;

	if (len <= 0)
		return (0);
	i = 0;
	while (i++ < len)
		write(fd, &chr, 1);
	return ((size_t)len);
}
