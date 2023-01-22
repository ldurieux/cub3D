/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:13:37 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/17 14:13:38 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_MAX_SIZE 10
#define BASE_10_LEN 10

void	ft_putnbr_fd(int n, int fd)
{
	int		copy;
	char	buf[INT_MAX_SIZE + 1];
	char	*buf_ptr;

	buf_ptr = &buf[INT_MAX_SIZE];
	copy = n;
	while (copy != 0)
	{
		*buf_ptr-- = (char)(ft_abs(copy % BASE_10_LEN) + '0');
		copy /= BASE_10_LEN;
	}
	copy = (n < 0) * '-' + (n == 0) * '0';
	if (copy)
		*buf_ptr-- = (char)copy;
	write(fd, buf_ptr + 1, (size_t)(&buf[INT_MAX_SIZE] - buf_ptr));
}
