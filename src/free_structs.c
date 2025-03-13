
#include "parser.h"

/**
 * Frees memory allocated for the texture paths in the game info.
 */
static void	free_infos(t_info *info)
{
	free(info->no);
	free(info->so);
	free(info->we);
	free(info->ea);
}

/**
 * Frees the memory allocated for the map.
 */
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}

/**
 * Prints an error message, frees game structures, and exits the program.
 */
void	ft_error_msg(char *str, t_game *game)
{
	free_strucs(game);
	printf("%s\n", str);
	exit(-1);
}

/**
 * Frees the game structure and its components.
 */
void	free_strucs(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = -1;
	if (game->mlx)
	{
		while (++i < 4)
			mlx_delete_image(game->mlx, game->walls[i]);
		mlx_terminate(game->mlx);
	}
	if (game->map)
	{
		ft_free_map(game->map);
		free(game->map);
	}
	free(game->row_len);
	free_infos(&game->info);
}
