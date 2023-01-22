/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:01:34 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/10 17:01:36 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	ft_printf_hassign(int64_t val, t_printf_conversion conv)
{
	if (conv.flags & F_Space_Prefixed && val >= 0)
		return (1);
	if (conv.flags & F_Force_Sign && val >= 0)
		return (1);
	if (val < 0)
		return (1);
	return (0);
}

static size_t	ft_printf_putsign(int fd, int64_t val, t_printf_conversion conv)
{
	if (conv.flags & F_Space_Prefixed && val >= 0)
		return ((size_t)write(fd, " ", 1));
	if (conv.flags & F_Force_Sign && val >= 0)
		return ((size_t)write(fd, "+", 1));
	if (val < 0)
		return ((size_t)write(fd, "-", 1));
	return (0);
}

static void	ft_printf_putint_init(char *a_chr, t_printf_conversion *conv,
									int *has_precision, size_t *res_len)
{
	*a_chr = (char)(' ' + ((conv->flags & F_Zero_Padded) != 0) * ('0' - ' '));
	*res_len = 0;
	*has_precision = conv->precision != -1;
}

int	ft_printf_putint(int fd, t_printf_conversion conv, int64_t val)
{
	char	*number;
	size_t	number_len;
	size_t	res_len;
	char	a_chr;
	int		has_precision;

	ft_printf_putint_init(&a_chr, &conv, &has_precision, &res_len);
	number = ft_printf_lltoa(val, conv, "0123456789", &number_len);
	conv.precision = (int)ft_max(conv.precision, (int64_t)number_len);
	conv.width = (int)ft_max(conv.precision, conv.width)
		- ft_printf_hassign(val, conv);
	if (!has_precision && conv.flags & F_Zero_Padded)
		res_len += ft_printf_putsign(fd, val, conv);
	if (!(conv.flags & F_Left_Adjusted))
		res_len += ft_printf_putalign(fd, conv.width - conv.precision, a_chr);
	if (!has_precision && !(conv.flags & F_Zero_Padded))
		res_len += ft_printf_putsign(fd, val, conv);
	if (has_precision)
		res_len += ft_printf_putsign(fd, val, conv);
	res_len += ft_printf_putalign(fd, conv.precision - (int)number_len, '0');
	res_len += (size_t)write(fd, number, number_len);
	if (conv.flags & F_Left_Adjusted)
		res_len += ft_printf_putalign(fd, conv.width - conv.precision, a_chr);
	free(number);
	return ((int)(res_len));
}
