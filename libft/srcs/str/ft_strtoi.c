/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:16:05 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 16:16:06 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BASE_10_LEN 10

static int	ft_is_digit(const char chr)
{
	return (chr >= '0' && chr <= '9');
}

int	ft_strtoi(const char *str, char **end_ptr)
{
	int	res;
	int	sign;
	int	tmp;

	if (!str)
		return (0);
	res = 0;
	sign = 1;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign -= 2 * (*str++ == '-');
	while (ft_is_digit(*str))
	{
		tmp = res * BASE_10_LEN + (*str++ - '0') * sign;
		if ((tmp < res && sign == 1) || (tmp > res && sign == -1))
		{
			res = INT32_MAX * (sign == 1) + INT32_MIN * (sign == -1);
			break ;
		}
		res = tmp;
	}
	if (end_ptr)
		*end_ptr = (char *)str;
	return (res);
}

long	ft_strtol(const char *str, char **end_ptr)
{
	long	res;
	int		sign;
	long	tmp;

	if (!str)
		return (0);
	res = 0;
	sign = 1;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign -= 2 * (*str++ == '-');
	while (ft_is_digit(*str))
	{
		tmp = res * BASE_10_LEN + (*str++ - '0') * (long)sign;
		if ((tmp < res && sign == 1) || (tmp > res && sign == -1))
		{
			res = INT64_MAX * (sign == 1) + INT64_MAX * (sign == -1);
			break ;
		}
		res = tmp;
	}
	if (end_ptr)
		*end_ptr = (char *)str;
	return (res);
}

long long	ft_strtoll(const char *str, char **end_ptr)
{
	long long	res;
	int			sign;
	long long	tmp;

	if (!str)
		return (0);
	res = 0;
	sign = 1;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign -= 2 * (*str++ == '-');
	while (ft_is_digit(*str))
	{
		tmp = res * BASE_10_LEN + (*str++ - '0') * (long long)sign;
		if ((tmp < res && sign == 1) || (tmp > res && sign == -1))
		{
			res = INT64_MAX * (sign == 1) + INT64_MIN * (sign == -1);
			break ;
		}
		res = tmp;
	}
	if (end_ptr)
		*end_ptr = (char *)str;
	return (res);
}
