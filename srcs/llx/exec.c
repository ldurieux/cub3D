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

void	llx_exit(t_llx *llx, int exit_code)
{
	if (exit_code < 0)
		exit_code *= -1;
	llx->exit_code = exit_code;
}
