/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:54:45 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:54:46 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include "libft.h"

typedef struct s_ftqueue_node
{
	void					*value;
	struct s_ftqueue_node	*next;
}	t_ftqueue_node;

typedef struct s_ftqueue
{
	t_ftqueue_node	*first;
	t_ftqueue_node	*last;
	size_t			size;
}	t_ftqueue;

t_ftqueue	*ft_queue_new(void);
void		ft_queue_delete(t_ftqueue *this);

int			ft_queue_push(t_ftqueue *this, void *value);
void		*ft_queue_pop(t_ftqueue *this);

void		ft_queue_iter(t_ftqueue *this, void (*f)(void *));

#endif // FT_QUEUE_H
