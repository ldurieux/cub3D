/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:02:50 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/24 02:02:52 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "llx.h"

int	llx_exec(t_llx *llx)
{
	mlx_loop(llx->mlx);
	return (0);
}

void	llx_exit(t_llx *llx, unsigned short exit_code)
{
	llx->exit_code = (int)exit_code;
}
