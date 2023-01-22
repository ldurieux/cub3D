/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:46:08 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/08 14:46:09 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CASE_OFFSET	32

int	ft_tolower(int chr)
{
	if (chr >= 'A' && chr <= 'Z')
		return (chr + CASE_OFFSET);
	return (chr);
}
