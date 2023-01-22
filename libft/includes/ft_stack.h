/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:21:17 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/07 00:21:20 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

typedef struct s_ftstack_node
{
	void					*value;
	struct s_ftstack_node	*prev;
}	t_ftstack_node;

typedef struct s_ftstack
{
	t_ftstack_node	*top;
	size_t			size;
}	t_ftstack;

t_ftstack	*ft_stack_new(void);
void		ft_stack_delete(t_ftstack *this);

int			ft_stack_push(t_ftstack *this, void *value);
void		*ft_stack_pop(t_ftstack *this);

void		ft_stack_iter(t_ftstack *this, void (*f)(void *));

#endif // FT_STACK_H
