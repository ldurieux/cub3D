/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_chrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:24:04 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/23 02:24:07 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "map_internal.h"

char	*eat_whitespace(char *str)
{
	while (ft_is_whitespace(*str))
		str++;
	return (str);
}

char	*eat_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	eat_inter_color(char **str)
{
	char	*cpy;

	cpy = eat_spaces(*str);
	if (*cpy == '\n')
		return (ft_dprintf(2, COLOR_UNEX_NL), 0);
	if (*cpy != ',')
		return (ft_dprintf(2, COLOR_UNEX_CHR), 0);
	cpy = eat_spaces(cpy + 1);
	if (*cpy == '\n')
		return (ft_dprintf(2, COLOR_UNEX_NL), 0);
	if (!ft_isdigit(*cpy))
		return (ft_dprintf(2, COLOR_UNEX_CHR), 0);
	*str = cpy;
	return (1);
}
