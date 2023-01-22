/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:36 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:38 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*res;
	char		*c_ptr;
	uint64_t	*i_ptr;
	size_t		mem_size;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	mem_size = count * size;
	res = malloc(mem_size);
	if (!res)
		return (NULL);
	i_ptr = (uint64_t *) res;
	while (mem_size > sizeof(uint64_t) - 1)
	{
		*i_ptr++ = 0;
		mem_size -= sizeof(uint64_t);
	}
	c_ptr = (char *) i_ptr;
	while (mem_size-- > 0)
		*c_ptr++ = 0;
	return (res);
}
