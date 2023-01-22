/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tocase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:07 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:13:08 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CASE_OFFSET 32

/*return -1 if chr is a lowercase letter
 *		  1 if chr is an uppercase letter
 *		  0 otherwise
*/
static int	ft_is_letter(const char chr)
{
	return ((chr >= 'a' && chr <= 'z') * -1 + (chr >= 'A' && chr <= 'Z'));
}

static int	ft_is_alphanum(const char chr)
{
	return (ft_is_letter(chr) || (chr >= '0' && chr <= '9'));
}

char	*ft_strlwr(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (ft_is_letter(str[i]) == 1)
			str[i] += CASE_OFFSET;
		i++;
	}
	return (str);
}

char	*ft_strupr(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (ft_is_letter(str[i]) == -1)
			str[i] -= CASE_OFFSET;
		i++;
	}
	return (str);
}

char	*ft_strcap(char *str)
{
	int		first_letter;
	size_t	i;
	int		is_letter;

	if (!str)
		return (NULL);
	first_letter = 1;
	i = 0;
	while (str[i])
	{
		if (ft_is_alphanum(str[i]))
		{
			is_letter = ft_is_letter(str[i]);
			if (is_letter == -1 && first_letter)
				str[i] -= CASE_OFFSET;
			else if (is_letter == 1 && !first_letter)
				str[i] += CASE_OFFSET;
			first_letter = 0;
		}
		else
			first_letter = 1;
		i++;
	}
	return (str);
}
