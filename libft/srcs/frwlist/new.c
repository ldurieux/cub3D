/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frwlist_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:56:38 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 14:56:39 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_frwlist.h"

t_ftfrwlist	*ft_frwlist_new(void)
{
	t_ftfrwlist	*res;

	res = malloc(sizeof(t_ftfrwlist));
	if (!res)
		return (NULL);
	res->size = 0;
	res->first = NULL;
	res->last = NULL;
	return (res);
}
