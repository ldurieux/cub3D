/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frwlist_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:56:28 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 14:56:35 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_frwlist.h"

t_ftfrwlist_node	*ft_frwlist_node_at(t_ftfrwlist *this, size_t index)
{
	t_ftfrwlist_node	*node;

	if (!this)
		return (NULL);
	if (index == this->size - 1)
		return (this->last);
	node = this->first;
	while (node && index--)
		node = node->next;
	return (node);
}

void	*ft_frwlist_value_at(t_ftfrwlist *this, size_t index)
{
	t_ftfrwlist_node	*node;

	node = ft_frwlist_node_at(this, index);
	if (!node)
		return (NULL);
	return (node->value);
}
