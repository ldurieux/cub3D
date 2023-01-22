/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frwlist_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:56:36 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 14:56:36 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_frwlist.h"

void	ft_frwlist_delete(t_ftfrwlist *this)
{
	t_ftfrwlist_node	*cur_node;
	t_ftfrwlist_node	*next_node;

	if (!this)
		return ;
	cur_node = this->first;
	while (cur_node)
	{
		next_node = cur_node->next;
		free(cur_node);
		cur_node = next_node;
	}
	free(this);
}
