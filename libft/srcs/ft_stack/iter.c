/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:29:16 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 20:29:21 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_iter(t_ftstack *this, void (*f)(void *))
{
	t_ftstack_node	*node;

	if (!this)
		return ;
	node = this->top;
	while (node)
	{
		f(node->value);
		node = node->prev;
	}
}
