/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:10:37 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/06 19:10:37 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int	ft_vector_push_back(t_ftvector *this, void *value)
{
	size_t	data_size;

	if (!this || !value)
		return (0);
	if (this->size >= this->_capacity)
		if (!ft_vector_reserve(this, this->_capacity * 2))
			return (0);
	data_size = this->_data_size;
	ft_memcpy(
		((char *)this->data) + this->size * data_size,
		value, data_size);
	this->size++;
	return (1);
}
