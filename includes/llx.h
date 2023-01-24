/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:26:17 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/23 19:26:19 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLX_H
# define LLX_H

# include <stdint.h>
# include "libft.h"
# include "mlx.h"

# define LLX_MAX_WIN	255

typedef struct s_llx_win	t_llx_win;
typedef struct s_llx		t_llx;

typedef struct s_llx
{
	void		*mlx;
	t_llx_win	*windows;
	void		(*on_exit)(t_llx *llx);
	void		*data;
	int			exit_code;
	uint8_t		last_win_id;
	uint8_t		win_count;
}	t_llx;

int		llx_init(t_llx *llx);
void	llx_destroy(t_llx *llx);
int		llx_exec(t_llx *llx);
void	llx_exit(t_llx *llx, int exit_code);

#endif // LLX_H
