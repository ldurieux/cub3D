/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:54:39 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:54:41 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	ft_queue_delete(t_ftqueue *this)
{
	t_ftqueue_node	*cur_node;
	t_ftqueue_node	*next_node;

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
