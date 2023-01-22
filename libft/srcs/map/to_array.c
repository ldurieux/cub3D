/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:59:37 by ldurieux          #+#    #+#             */
/*   Updated: 2022/12/15 10:59:42 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

static void	bucket_to_array(t_ftfrwlist *bucket, void **arr,
							size_t *arr_idx, void *(*f)(void *))
{
	t_ftfrwlist_node	*list_node;
	t_ftmap_node		*map_node;

	list_node = bucket->first;
	while (list_node)
	{
		map_node = list_node->value;
		arr[*arr_idx] = f(map_node->value);
		list_node = list_node->next;
		(*arr_idx)++;
	}
}

void	*ft_map_to_array(t_ftmap *this, void *(*f)(void *))
{
	size_t	bucket_idx;
	size_t	arr_idx;
	void	**arr;

	if (!this)
		return (NULL);
	arr = malloc(sizeof(void *) * (this->size + 1));
	if (!arr)
		return (NULL);
	bucket_idx = (size_t)-1;
	arr_idx = 0;
	while (++bucket_idx < this->_capacity)
		bucket_to_array(this->_buckets + bucket_idx, arr, &arr_idx, f);
	arr[this->size] = NULL;
	return (arr);
}
