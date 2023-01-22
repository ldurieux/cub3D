/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:35:32 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 13:35:33 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static inline t_ftlist_node	*node_from_end(t_ftlist *this, size_t index)
{
	t_ftlist_node	*node;
	size_t			cur_index;

	cur_index = this->size - 1;
	node = this->last;
	while (node && cur_index-- != index)
		node = node->prev;
	return (node);
}

static inline t_ftlist_node	*node_from_start(t_ftlist *this, size_t index)
{
	t_ftlist_node	*node;

	node = this->first;
	while (node && index--)
		node = node->next;
	return (node);
}

t_ftlist_node	*ft_list_node_at(t_ftlist *this, size_t index)
{
	if (!this)
		return (NULL);
	if (index > this->size / 2)
		return (node_from_end(this, index));
	return (node_from_start(this, index));
}

void	*ft_list_value_at(t_ftlist *this, size_t index)
{
	t_ftlist_node	*node;

	node = ft_list_node_at(this, index);
	if (!node)
		return (NULL);
	return (node->value);
}
