/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:10:38 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/06 19:10:39 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static inline void	*ft_simple_realloc(void *ptr, size_t size,
									size_t new_size)
{
	void	*res;

	if (!ptr)
		return (malloc(new_size));
	res = malloc(new_size);
	if (!res)
		return (NULL);
	if (size > new_size)
		size = new_size;
	ft_memcpy(res, ptr, size);
	free(ptr);
	return (res);
}

int	ft_vector_reserve(t_ftvector *this, size_t capacity)
{
	void	*new_data;
	size_t	data_size;

	if (!this || capacity < this->size)
		return (0);
	data_size = this->_data_size;
	new_data = ft_simple_realloc(this->data,
			data_size * this->_capacity,
			data_size * capacity
			);
	if (!new_data)
		return (0);
	this->data = new_data;
	this->_capacity = capacity;
	return (1);
}
