/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:21:06 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:21:10 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_delete(t_ftstack *this)
{
	t_ftstack_node	*cur_node;
	t_ftstack_node	*prev_node;

	if (!this)
		return ;
	cur_node = this->top;
	while (cur_node)
	{
		prev_node = cur_node->prev;
		free(cur_node);
		cur_node = prev_node;
	}
	free(this);
}
