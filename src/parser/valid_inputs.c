#include "parser.h"

void	validate_info(t_game *game)
{
	if (!game->info.no || !game->info.so || !game->info.we || !game->info.ea)
		ft_error_msg("error, missing textures(NO, SO, WE, EA).", game);
}

/**
 * Calculates the map's size and records it in game
 */
void	calc_map_size(t_game *game)
{
	int	i;

	while (game->map[game->map_height])
		game->map_height++;
	game->row_len = ft_calloc(game->map_height, sizeof(int));
	i = -1;
	while (game->map[++i])
		game->row_len[i] = ft_strlen(i);
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
			if (setup_player(game->map[i][j]))
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
