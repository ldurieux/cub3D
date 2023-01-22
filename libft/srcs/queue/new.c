/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:54:41 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:54:42 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

t_ftqueue	*ft_queue_new(void)
{
	t_ftqueue	*res;

	res = malloc(sizeof(t_ftqueue));
	if (!res)
		return (NULL);
	res->first = NULL;
	res->last = NULL;
	res->size = 0;
	return (res);
}
