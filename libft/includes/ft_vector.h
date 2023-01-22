/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:10:40 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/06 19:10:42 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_ftvector
{
	void	*data;
	size_t	size;
	size_t	_data_size;
	size_t	_capacity;
}	t_ftvector;

t_ftvector	*ft_vector_new(size_t data_size, size_t capacity);
void		ft_vector_delete(t_ftvector *this);

int			ft_vector_push_back(t_ftvector *this, void *value);
void		*ft_vector_pop_back(t_ftvector *this);

int			ft_vector_reserve(t_ftvector *this, size_t capacity);

#endif // FT_VECTOR_H
