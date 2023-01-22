/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:54:44 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:54:45 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

int	ft_queue_push(t_ftqueue *this, void *value)
{
	t_ftqueue_node	*node;

	if (!this || !value)
		return (0);
	node = malloc(sizeof(t_ftqueue_node));
	if (!node)
		return (0);
	node->value = value;
	node->next = NULL;
	this->size++;
	if (!this->first)
	{
		this->first = node;
		this->last = node;
		return (1);
	}
	this->last->next = node;
	this->last = node;
	return (1);
}
