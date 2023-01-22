/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:43 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:44 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	ft_factorial(int64_t value)
{
	int64_t		i;
	uint64_t	res;

	if (value < 0)
		return (0);
	res = 1;
	i = 1;
	while (++i <= value)
		res *= i;
	return (res);
}
