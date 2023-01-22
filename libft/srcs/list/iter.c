/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:29:12 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 20:29:13 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_iter(t_ftlist *this, void (*f)(void *))
{
	t_ftlist_node	*node;

	if (!this)
		return ;
	node = this->first;
	while (node)
	{
		f(node->value);
		node = node->next;
	}
}
