/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:11:25 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:11:28 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, NULL));
}

long	ft_atol(const char *str)
{
	return (ft_strtol(str, NULL));
}

long long	ft_atoll(const char *str)
{
	return (ft_strtoll(str, NULL));
}
