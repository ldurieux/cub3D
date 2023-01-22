/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:21:12 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:21:12 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_ftstack	*ft_stack_new(void)
{
	t_ftstack	*res;

	res = malloc(sizeof(t_ftstack));
	if (!res)
		return (NULL);
	res->size = 0;
	res->top = NULL;
	return (res);
}
