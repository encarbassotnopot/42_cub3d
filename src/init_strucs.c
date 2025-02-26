
#include "cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (0);
	while (line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	init_info_struc(t_game *game)
{
	game->info.no = NULL;
	game->info.so = NULL;
	game->info.we = NULL;
	game->info.ea = NULL;
	game->info.floor = NULL;
	game->info.ceiling = NULL;
}

void	init_structs(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		ft_error_msg("error malloc map");
	game->map->mapa = NULL;
	game->map->player_count = 0;
	init_info_struc(game);
}
