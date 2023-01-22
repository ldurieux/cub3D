/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frwlist_iter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:29:11 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 20:29:12 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_frwlist.h"

void	ft_frwlist_iter(t_ftfrwlist *this, void (*f)(void *))
{
	t_ftfrwlist_node	*node;

	if (!this)
		return ;
	node = this->first;
	while (node)
	{
		f(node->value);
		node = node->next;
	}
}
