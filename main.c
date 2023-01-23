#include "map.h"

int main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_dprintf(2, "Invalid arguments count\n"), 0);
	if (!map_load(&map, argv[1]))
		return (map_free(&map), 1);
	return (0);
}
