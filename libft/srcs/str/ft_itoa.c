/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:46 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:46 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_MAX_SIZE 10
#define LONG_MAX_SIZE 19
#define LLONG_MAX_SIZE 19
#define BASE_10_LEN 10

static char	*ft_itoa_res(char *buf, size_t len)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, buf, len);
	res[len] = '\0';
	return (res);
}

char	*ft_itoa(int value)
{
	int		copy;
	char	buf[INT_MAX_SIZE + 1];
	char	*buf_ptr;

	buf_ptr = &buf[INT_MAX_SIZE];
	copy = value;
	while (copy != 0)
	{
		*buf_ptr-- = (char)(ft_abs(copy % BASE_10_LEN) + '0');
		copy /= BASE_10_LEN;
	}
	copy = (value < 0) * '-' + (value == 0) * '0';
	if (copy)
		*buf_ptr-- = (char)copy;
	return (ft_itoa_res(buf_ptr + 1, &buf[INT_MAX_SIZE] - buf_ptr));
}

char	*ft_ltoa(long value)
{
	long	copy;
	char	buf[LONG_MAX_SIZE + 1];
	char	*buf_ptr;

	buf_ptr = &buf[LONG_MAX_SIZE];
	copy = value;
	while (copy != 0)
	{
		*buf_ptr-- = (char)(ft_abs(copy % BASE_10_LEN) + '0');
		copy /= BASE_10_LEN;
	}
	copy = (value < 0) * '-' + (value == 0) * '0';
	if (copy)
		*buf_ptr-- = (char)copy;
	return (ft_itoa_res(buf_ptr + 1, &buf[LONG_MAX_SIZE] - buf_ptr));
}

char	*ft_lltoa(long long value)
{
	long long	copy;
	char		buf[LLONG_MAX_SIZE + 1];
	char		*buf_ptr;

	buf_ptr = &buf[LLONG_MAX_SIZE];
	copy = value;
	while (copy != 0)
	{
		*buf_ptr-- = (char)(ft_abs(copy % BASE_10_LEN) + '0');
		copy /= BASE_10_LEN;
	}
	copy = (value < 0) * '-' + (value == 0) * '0';
	if (copy)
		*buf_ptr-- = (char)copy;
	return (ft_itoa_res(buf_ptr + 1, &buf[LLONG_MAX_SIZE] - buf_ptr));
}
