/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frwlist_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:56:39 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 14:56:40 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_frwlist.h"

void	*ft_frwlist_remove_at(t_ftfrwlist *this, size_t index)
{
	t_ftfrwlist_node	*before;
	t_ftfrwlist_node	*node;
	void				*res;

	if (index >= this->size)
		return (NULL);
	before = ft_frwlist_node_at(this, index - 1);
	if (before)
	{
		node = before->next;
		before->next = node->next;
	}
	else
	{
		node = ft_frwlist_node_at(this, index);
		this->first = node->next;
	}
	if (!node->next)
		this->last = before;
	res = node->value;
	free(node);
	this->size--;
	return (res);
}

void	*ft_frwlist_pop_front(t_ftfrwlist *this)
{
	return (ft_frwlist_remove_at(this, 0));
}

void	*ft_frwlist_pop_back(t_ftfrwlist *this)
{
	return (ft_frwlist_remove_at(this, this->size - 1));
}
