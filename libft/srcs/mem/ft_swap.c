/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:11 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:13:12 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	void	*tmp;

	if (!a || !b)
		return ;
	tmp = malloc(size);
	if (!tmp)
		return ;
	ft_memcpy(tmp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, tmp, size);
	free(tmp);
}
