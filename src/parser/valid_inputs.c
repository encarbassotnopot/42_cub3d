#include "parser.h"

void	validate_info(t_game *game)
{
	if (!game->info.no || !game->info.so || !game->info.we || !game->info.ea)
		ft_error_msg("error, missing textures(NO, SO, WE, EA).", game);
}

void	validate_map(t_game *game)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (is_player(game->map[i][j]))
				player_count++;
			else if (ft_strchr("01 ", game->map[i][j]) == NULL)
				ft_error_msg("error map character", game);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		ft_error_msg("error players number", game);
}
