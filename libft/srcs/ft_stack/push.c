/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:21:15 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:21:16 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_push(t_ftstack *this, void *value)
{
	t_ftstack_node	*node;

	if (!this || !value)
		return (0);
	node = malloc(sizeof(t_ftstack_node));
	if (!node)
		return (0);
	node->prev = this->top;
	node->value = value;
	this->top = node;
	this->size++;
	return (1);
}
