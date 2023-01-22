/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:12:19 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 20:12:20 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

static inline int	insert(t_ftmap *this, const char *key, void *value)
{
	size_t			index;
	t_ftfrwlist		*bucket;
	t_ftmap_node	*node;

	node = ft_map_find_node(this, key);
	if (node)
	{
		node->value = value;
		return (1);
	}
	node = malloc(sizeof(t_ftmap_node));
	if (!node)
		return (0);
	node->key = (char *)key;
	node->value = value;
	index = ft_map_hash(key) % this->_capacity;
	bucket = this->_buckets + index;
	ft_frwlist_push_back(bucket, node);
	this->size++;
	return (1);
}

int	ft_map_insert(t_ftmap *this, const char *key, void *value)
{
	char		*copy_key;

	if (!this || !key)
		return (0);
	copy_key = ft_strdup(key);
	if (!copy_key)
		return (0);
	return (insert(this, copy_key, value));
}

int	ft_map_insert_n(t_ftmap *this, const char *key, size_t key_size,
						void *value)
{
	char		*copy_key;

	if (!this || !key)
		return (0);
	copy_key = ft_strndup(key, key_size);
	if (!copy_key)
		return (0);
	return (insert(this, copy_key, value));
}
