/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:50 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:51 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_power(int64_t value, int64_t power)
{
	int64_t	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power-- > 0)
		res *= value;
	return (res);
}
