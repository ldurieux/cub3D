/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:35:35 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 13:35:36 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static inline void	insert_between(t_ftlist_node *node,
								t_ftlist_node *before, t_ftlist_node *after)
{
	if (before)
		before->next = node;
	if (after)
		after->prev = node;
	node->prev = before;
	node->next = after;
}

static inline void	get_nodes(t_ftlist *this, t_ftlist_node **before,
							t_ftlist_node **after, size_t index)
{
	if (index == this->size)
	{
		*after = NULL;
		*before = this->last;
		return ;
	}
	*after = ft_list_node_at(this, index);
	*before = (*after)->prev;
}

int	ft_list_insert(t_ftlist *this, size_t index, void *value)
{
	t_ftlist_node	*before;
	t_ftlist_node	*after;
	t_ftlist_node	*node;

	if (index > this->size)
		return (0);
	node = malloc(sizeof(t_ftlist_node));
	if (!node)
		return (0);
	get_nodes(this, &before, &after, index);
	if (index == this->size)
		this->last = node;
	if (index == 0)
		this->first = node;
	insert_between(node, before, after);
	node->value = value;
	this->size++;
	return (1);
}

int	ft_list_push_front(t_ftlist *this, void *value)
{
	return (ft_list_insert(this, 0, value));
}

int	ft_list_push_back(t_ftlist *this, void *value)
{
	return (ft_list_insert(this, this->size, value));
}
