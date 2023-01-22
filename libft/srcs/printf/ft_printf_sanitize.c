/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sanitize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:57:33 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/20 14:57:34 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

void	ft_printf_sanitize(t_printf_conversion *conv)
{
	if (conv->conv & C_Unsigned)
		conv->flags &= ~(F_Space_Prefixed | F_Force_Sign);
	if (conv->conv & C_Decimal && !(conv->conv & C_Double))
		conv->flags &= ~F_Alternate;
	if ((conv->conv & C_Int) && (conv->conv & C_Decimal))
		conv->flags &= ~F_Alternate;
	if (conv->flags & F_Left_Adjusted)
		conv->flags &= ~F_Zero_Padded;
	if (conv->flags & F_Force_Sign)
		conv->flags &= ~F_Space_Prefixed;
	if (conv->conv & C_Get_Written)
	{
		conv->flags = 0;
		conv->width = 0;
		conv->precision = -1;
	}
	if (conv->width < 0)
	{
		conv->flags |= F_Left_Adjusted;
		conv->width *= -1;
	}
	if (conv->precision < 0)
		conv->precision = -1;
	if (conv->precision != -1)
		conv->flags &= ~F_Zero_Padded;
}
