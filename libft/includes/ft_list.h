/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:35:39 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 13:35:40 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

typedef struct s_ftlist_node
{
	void					*value;
	struct s_ftlist_node	*prev;
	struct s_ftlist_node	*next;
}	t_ftlist_node;

typedef struct s_ftlist
{
	t_ftlist_node	*first;
	t_ftlist_node	*last;
	size_t			size;
}	t_ftlist;

t_ftlist		*ft_list_new(void);
void			ft_list_delete(t_ftlist *this);

int				ft_list_insert(t_ftlist *this, size_t index, void *value);
int				ft_list_push_front(t_ftlist *this, void *value);
int				ft_list_push_back(t_ftlist *this, void *value);
void			*ft_list_remove_at(t_ftlist *this, size_t index);
void			*ft_list_pop_front(t_ftlist *this);
void			*ft_list_pop_back(t_ftlist *this);

t_ftlist_node	*ft_list_node_at(t_ftlist *this, size_t index);
void			*ft_list_value_at(t_ftlist *this, size_t index);

void			ft_list_iter(t_ftlist *this, void (*f)(void *));

#endif // FT_LIST_H
