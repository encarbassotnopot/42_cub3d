#include "cub3d.h"

void	debug_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->mapa)
	{
		printf("no existeix mapa.\n");
		return ;
	}
	printf("Mapa:\n");
	while (map->mapa[i])
	{
		printf("%s\n", map->mapa[i]);
		i++;
	}
	printf("num jugadors: %d\n", map->player_count);
}

void	debug_info(t_info *info)
{
	printf("Información de texturas y colores:\n");
	printf("NO: %s\n", info->no);
	printf("SO: %s\n", info->so);
	printf("WE: %s\n", info->we);
	printf("EA: %s\n", info->ea);
}
