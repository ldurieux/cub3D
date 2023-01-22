/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:12:17 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 20:12:18 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

static inline void	free_bucket(t_ftfrwlist *bucket)
{
	t_ftfrwlist_node	*frw_cur_node;
	t_ftfrwlist_node	*frw_next_node;
	t_ftmap_node		*map_node;

	frw_cur_node = bucket->first;
	while (frw_cur_node)
	{
		frw_next_node = frw_cur_node->next;
		map_node = frw_cur_node->value;
		free(map_node->key);
		free(map_node);
		free(frw_cur_node);
		frw_cur_node = frw_next_node;
	}
}

void	ft_map_delete(t_ftmap *this)
{
	size_t		bucket_idx;
	t_ftfrwlist	*buckets;

	if (!this)
		return ;
	buckets = this->_buckets;
	bucket_idx = -1;
	while (++bucket_idx < this->_capacity)
		free_bucket(buckets + bucket_idx);
	free(buckets);
	free(this);
}
