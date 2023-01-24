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

/**
 * @brief contains general information on the UI
 *
 * data may be set by the user and can take any value and will be sent to every
 * window with the trigger llx_win.on_loop
 *
 * on_exit may be set by the user
 */
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

/**
 * @brief initialize an llx instance, this should be done only once
 * @param struct to initialize
 * @return 0 if something went wrong
 */
int		llx_init(t_llx *llx);

/**
 * @brief close every window and closes them, triggering llx_win.on_close
 * @param llx pointer
 */
void	llx_destroy(t_llx *llx);

/**
 * @brief start the UI loop, this function will never return and should only be
 * called once
 * @param llx pointer
 * @return 0
 */
int		llx_exec(t_llx *llx);

/**
 * @brief cause the program to exit, triggering llx.on_exit. This function may
 * not exit when called, but is guarenteed to exit soon after
 * @param llx pointer
 * @param program exit code
 */
void	llx_exit(t_llx *llx, unsigned short exit_code);

#endif // LLX_H
