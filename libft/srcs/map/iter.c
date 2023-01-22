/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:29:14 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/08 01:18:38 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

static void	iter_bucket(t_ftfrwlist *bucket, void (*f)(void *))
{
	t_ftfrwlist_node	*list_node;
	t_ftmap_node		*map_node;

	list_node = bucket->first;
	while (list_node)
	{
		map_node = list_node->value;
		f(map_node->value);
		list_node = list_node->next;
	}
}

void	ft_map_iter(t_ftmap *this, void (*f)(void *))
{
	size_t		index;

	if (!this)
		return ;
	index = (size_t)-1;
	while (++index < this->_capacity)
		iter_bucket(this->_buckets + index, f);
}

static void	iter_node_bucket(t_ftfrwlist *bucket, void (*f)(char *, void *))
{
	t_ftfrwlist_node	*list_node;
	t_ftmap_node		*map_node;

	list_node = bucket->first;
	while (list_node)
	{
		map_node = list_node->value;
		f(map_node->key, map_node->value);
		list_node = list_node->next;
	}
}

void	ft_map_iter_node(t_ftmap *this, void (*f)(char *, void *))
{
	size_t		index;

	if (!this)
		return ;
	index = (size_t)-1;
	while (++index < this->_capacity)
		iter_node_bucket(this->_buckets + index, f);
}
