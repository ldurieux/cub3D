/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:12:18 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 20:12:19 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_ftmap_node	*ft_map_find_node(t_ftmap *this, const char *key)
{
	t_ftmap_node		*map_node;
	t_ftfrwlist			*bucket;
	t_ftfrwlist_node	*list_node;
	size_t				index;

	if (!this)
		return (NULL);
	index = ft_map_hash(key) % this->_capacity;
	bucket = this->_buckets + index;
	list_node = bucket->first;
	while (list_node)
	{
		map_node = list_node->value;
		if (ft_strcmp(map_node->key, key) == 0)
			return (map_node);
		list_node = list_node->next;
	}
	return (NULL);
}

void	*ft_map_find(t_ftmap *this, const char *key)
{
	t_ftmap_node	*node;

	if (!this || !key)
		return (NULL);
	node = ft_map_find_node(this, key);
	if (!node)
		return (NULL);
	return (node->value);
}
