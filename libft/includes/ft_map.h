/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:12:33 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/08 01:11:40 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "stdlib.h"
# include "ft_frwlist.h"

typedef struct s_ftmap_node
{
	void	*value;
	char	*key;
}	t_ftmap_node;

typedef struct s_ftmap
{
	t_ftfrwlist	*_buckets;
	size_t		_capacity;
	size_t		size;
}	t_ftmap;

t_ftmap			*ft_map_new(size_t capacity);
void			ft_map_delete(t_ftmap *this);

int				ft_map_insert(t_ftmap *this, const char *key, void *value);
int				ft_map_insert_n(t_ftmap *this, const char *key, size_t key_size,
					void *value);
void			*ft_map_remove(t_ftmap *this, const char *key);

t_ftmap_node	*ft_map_find_node(t_ftmap *this, const char *key);
void			*ft_map_find(t_ftmap *this, const char *key);

void			ft_map_iter(t_ftmap *this, void (*f)(void *));
void			ft_map_iter_node(t_ftmap *this, void (*f)(char *, void *));

void			*ft_map_to_array(t_ftmap *this, void *(*f)(void *));

//NOLINTBEGIN(readability-magic-numbers)
static inline uint64_t	ft_map_hash(const char *key)
{
	register uint64_t	hash;

	hash = 0;
	while (*key)
		hash = (*key++ + (hash << 6)) + ((hash << 16) - hash);
	return (hash);
}
//NOLINTEND

#endif // FT_MAP_H
