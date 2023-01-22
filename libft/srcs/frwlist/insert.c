/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frwlist_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:56:37 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 14:56:38 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_frwlist.h"

int	ft_frwlist_insert(t_ftfrwlist *this, size_t index, void *value)
{
	t_ftfrwlist_node	*before;
	t_ftfrwlist_node	*node;

	if (index > this->size)
		return (0);
	node = malloc(sizeof(t_ftfrwlist_node));
	if (!node)
		return (0);
	node->next = NULL;
	if (index != 0)
	{
		before = ft_frwlist_node_at(this, index - 1);
		node->next = before->next;
		before->next = node;
	}
	else
	{
		node->next = this->first;
		this->first = node;
	}
	if (index == this->size)
		this->last = node;
	node->value = value;
	this->size++;
	return (1);
}

int	ft_frwlist_push_front(t_ftfrwlist *this, void *value)
{
	return (ft_frwlist_insert(this, 0, value));
}

int	ft_frwlist_push_back(t_ftfrwlist *this, void *value)
{
	return (ft_frwlist_insert(this, this->size, value));
}
