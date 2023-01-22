/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:54:43 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:54:43 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	*ft_queue_pop(t_ftqueue *this)
{
	void			*res;
	t_ftqueue_node	*node;

	if (!this)
		return (NULL);
	node = this->first;
	if (!node)
		return (NULL);
	this->first = node->next;
	if (!node->next)
		this->last = NULL;
	res = node->value;
	free(node);
	this->size--;
	return (res);
}
