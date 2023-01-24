/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:24:14 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/23 02:24:26 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

static char	*list_to_str(t_ftfrwlist *list)
{
	size_t				size;
	size_t				len;
	t_ftfrwlist_node	*node;
	char				*res;

	size = 0;
	node = list->first;
	while (node)
	{
		size += ft_strlen(node->value);
		node = node->next;
	}
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	node = list->first;
	size = 0;
	while (node)
	{
		len = ft_strlen(node->value);
		ft_memcpy(res + size, node->value, len);
		size += len;
		node = node->next;
	}
	return (res[size] = '\0', res);
}

static char	*read_all_res(t_ftfrwlist *list, char *buffer)
{
	if (list->size == 0)
		return (ft_frwlist_delete(list), ft_strdup(""));
	buffer = list_to_str(list);
	ft_frwlist_iter(list, free);
	return (ft_frwlist_delete(list), buffer);
}

#define READ_SIZE 64

char	*read_all(int fd)
{
	t_ftfrwlist	*list;
	char		*buffer;
	ssize_t		bytes_read;

	list = ft_frwlist_new();
	if (!list)
		return (NULL);
	while (list->size == 0 || bytes_read == READ_SIZE)
	{
		buffer = malloc(sizeof(char) * (READ_SIZE + 1));
		if (!buffer)
			return (ft_frwlist_iter(list, free), ft_frwlist_delete(list), NULL);
		bytes_read = read(fd, buffer, READ_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			break ;
		}
		buffer[bytes_read] = '\0';
		if (!ft_frwlist_push_back(list, buffer))
			return (ft_frwlist_iter(list, free), ft_frwlist_delete(list), NULL);
	}
	return (read_all_res(list, buffer));
}
