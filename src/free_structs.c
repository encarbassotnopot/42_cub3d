
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
	if (!map || !(map[i]))
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
		if (!map[i])
			return ;
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
	if (game->map)
	{
		ft_free_map(game->map);
		free(game->map);
	}
	free_infos(&game->info);
}
