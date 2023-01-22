/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:12:20 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 20:12:21 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

#define DEFAULT_CAPACITY	50

t_ftmap	*ft_map_new(size_t capacity)
{
	t_ftmap	*res;

	if (capacity == 0)
		capacity = DEFAULT_CAPACITY;
	res = malloc(sizeof(t_ftmap));
	if (!res)
		return (NULL);
	res->_buckets = ft_calloc(capacity, sizeof(t_ftfrwlist));
	if (!res->_buckets)
	{
		free(res);
		return (NULL);
	}
	res->_capacity = capacity;
	res->size = 0;
	return (res);
}
