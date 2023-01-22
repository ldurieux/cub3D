/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:21:13 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:21:14 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	*ft_stack_pop(t_ftstack *this)
{
	t_ftstack_node	*node;
	void			*res;

	if (!this)
		return (NULL);
	node = this->top;
	if (!node)
		return (NULL);
	res = node->value;
	this->top = node->prev;
	free(node);
	this->size--;
	return (res);
}
