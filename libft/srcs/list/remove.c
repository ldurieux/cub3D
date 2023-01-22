/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:35:38 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 13:35:39 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_list_remove_at(t_ftlist *this, size_t index)
{
	t_ftlist_node	*before;
	t_ftlist_node	*after;
	t_ftlist_node	*node;
	void			*res;

	if (index >= this->size)
		return (NULL);
	node = ft_list_node_at(this, index);
	if (!node)
		return (NULL);
	before = node->prev;
	after = node->next;
	if (before)
		before->next = after;
	else
		this->first = after;
	if (after)
		after->prev = before;
	else
		this->last = before;
	res = node->value;
	free(node);
	this->size--;
	return (res);
}

void	*ft_list_pop_front(t_ftlist *this)
{
	return (ft_list_remove_at(this, 0));
}

void	*ft_list_pop_back(t_ftlist *this)
{
	return (ft_list_remove_at(this, this->size - 1));
}
