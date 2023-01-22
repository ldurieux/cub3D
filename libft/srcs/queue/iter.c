/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:29:15 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 20:29:16 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	ft_queue_iter(t_ftqueue *this, void (*f)(void *))
{
	t_ftqueue_node	*node;

	if (!this)
		return ;
	node = this->first;
	while (node)
	{
		f(node->value);
		node = node->next;
	}
}
