/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:12:21 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 20:12:32 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

static void	*free_node(t_ftmap_node *node)
{
	char	*res;

	res = node->value;
	free(node->key);
	free(node);
	return (res);
}

void	*ft_map_remove(t_ftmap *this, const char *key)
{
	size_t				index;
	t_ftfrwlist			*bucket;
	t_ftfrwlist_node	*list_node;
	t_ftmap_node		*node;

	if (!this || !key)
		return (NULL);
	index = ft_map_hash(key) % this->_capacity;
	bucket = this->_buckets + index;
	index = 0;
	list_node = bucket->first;
	while (list_node)
	{
		node = list_node->value;
		if (ft_strcmp(node->key, key) == 0)
			break ;
		list_node = list_node->next;
		index++;
	}
	if (!list_node)
		return (NULL);
	ft_frwlist_remove_at(bucket, index);
	this->size--;
	return (free_node(node));
}
