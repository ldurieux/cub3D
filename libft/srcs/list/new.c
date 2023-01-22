/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:35:37 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 13:35:37 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_ftlist	*ft_list_new(void)
{
	t_ftlist	*res;

	res = malloc(sizeof(t_ftlist));
	if (!res)
		return (NULL);
	res->size = 0;
	res->first = NULL;
	res->last = NULL;
	return (res);
}
