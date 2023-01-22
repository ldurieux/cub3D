/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:46:12 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/08 14:46:13 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CASE_OFFSET	32

int	ft_toupper(int chr)
{
	if (chr >= 'a' && chr <= 'z')
		return (chr - CASE_OFFSET);
	return (chr);
}
