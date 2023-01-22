/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frwlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:56:40 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 14:56:47 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRWLIST_H
# define FT_FRWLIST_H

# include "libft.h"

typedef struct s_ftfrwlist_node
{
	void					*value;
	struct s_ftfrwlist_node	*next;
}	t_ftfrwlist_node;

typedef struct s_ftfrwlist
{
	t_ftfrwlist_node	*first;
	t_ftfrwlist_node	*last;
	size_t				size;
}	t_ftfrwlist;

t_ftfrwlist			*ft_frwlist_new(void);
void				ft_frwlist_delete(t_ftfrwlist *this);

int					ft_frwlist_insert(t_ftfrwlist *this, size_t index,
						void *value);
int					ft_frwlist_push_front(t_ftfrwlist *this, void *value);
int					ft_frwlist_push_back(t_ftfrwlist *this, void *value);
void				*ft_frwlist_remove_at(t_ftfrwlist *this, size_t index);
void				*ft_frwlist_pop_front(t_ftfrwlist *this);
void				*ft_frwlist_pop_back(t_ftfrwlist *this);

t_ftfrwlist_node	*ft_frwlist_node_at(t_ftfrwlist *this, size_t index);
void				*ft_frwlist_value_at(t_ftfrwlist *this, size_t index);

void				ft_frwlist_iter(t_ftfrwlist *this, void (*f)(void *));

#endif // FT_FRWLIST_H
