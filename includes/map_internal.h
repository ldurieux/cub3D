/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:00:43 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/22 20:00:44 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INTERNAL_H
# define MAP_INTERNAL_H

# include <fcntl.h>
# include "ft_frwlist.h"
# include "ft_printf.h"

# define BAD_ALLOC "Error\nCouldn't allocate memory\n"
# define INVALID_FORMAT "Error\nInvalid file format %s\n"
# define OPEN_ERROR "Error\nCouldn't open file %s\n"
# define METADATA_INVALID_HEADER "Error\nInvalid metadata header\n"
# define METADATA_DUPLICATE_HEADER "Error\nDuplicated metadata header\n"
# define METADATA_UNEX_NL "Error\nUnexpected new line after metadata header\n"
# define METADATA_UNEX_CHR "Error\nUnexpected character after metadata header\n"
# define METADATA_MISSING "Error\nMissing metadata header\n"
# define COLOR_INVALID "Error\nInvalid color\n"
# define COLOR_UNEX_NL "Error\nUnexpected new line in color\n"
# define COLOR_UNEX_CHR "Error\nUnexpected character in color\n"
# define MAP_NOT_FOUND "Error\nMap not found\n"
# define MAP_DATA_NOT_FOUND "Error\nMap data not found\n"
# define MAP_UNEX_CHR "Error\nUnexpected character in map data\n"
# define MAP_MULTI_SPAWN "Error\nMultiple spawn points\n"
# define MAP_NO_SPAWN "Error\nNo spawn points\n"
# define MAP_NOT_CLOSED "Error\nMap not closed\n"
# define XPM_INVALID "Error\nInvalid xpm\n"

# define MAP_CHRS "01NSEW"

typedef enum e_field
{
	North_Tex = 0x1,
	South_Tex = 0x2,
	East_Tex = 0x4,
	West_Tex = 0x8,
	Floor_Col = 0x10,
	Ceil_Col = 0x20,
}	t_field;

typedef struct s_map	t_map;

int		parse(t_map *map, char *raw, void *mlx);
int		parse_metadata(t_map *map, char **raw);
int		parse_map(t_map *map, char *raw);

char	*eat_whitespace(char *str);
char	*eat_spaces(char *str);
int		eat_inter_color(char **str);

char	*read_all(int fd);

#endif // MAP_INTERNAL_H
