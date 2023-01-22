/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:10:33 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/06 19:10:34 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

#define DEFAULT_CAPACITY	50

t_ftvector	*ft_vector_new(size_t data_size, size_t capacity)
{
	t_ftvector	*this;

	this = malloc(sizeof(t_ftvector));
	if (!this)
		return (NULL);
	if (capacity == 0)
		capacity = DEFAULT_CAPACITY;
	this->data = malloc(data_size * capacity);
	if (!this->data)
	{
		free(this);
		return (NULL);
	}
	this->size = 0;
	this->_data_size = data_size;
	this->_capacity = capacity;
	return (this);
}
