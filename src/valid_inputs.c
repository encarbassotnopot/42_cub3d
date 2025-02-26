#include "cub3d.h"

void	validate_info(t_game *game)
{
	if (!game->info.no || !game->info.so || !game->info.we || !game->info.ea)
		ft_error_msg("error, missing textures(NO, SO, WE, EA).");
}

void	validate_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->mapa[i])
	{
		j = 0;
		while (game->map->mapa[i][j])
		{
			if (is_player(game->map->mapa[i][j]))
				game->map->player_count++;
			else if (ft_strchr("01 ", game->map->mapa[i][j]) == NULL)
				ft_error_msg("error map character");
			j++;
		}
		i++;
	}
	if (game->map->player_count != 1)
		ft_error_msg("error players number");
}
