#include "parser.h"

/**
 * Recursive function to perform a search across the entire map.
 * fill the cells that are within the map boundaries and surrounded
 * by walls with 'X'.
 * Error if it detects an area not enclosed.
 */
static void	flood_fill(t_game *game, int i, int j, int rows)
{
	if (i < 0 || i >= rows || j < 0 || j >= (int)ft_strlen(game->map[i]))
		ft_error_msg("map not enclosed by walls", game);
	if (game->map[i][j] == '1' || game->map[i][j] == 'X')
		return ;
	if (game->map[i][j] == ' ')
		ft_error_msg("map not enclosed by walls", game);
	game->map[i][j] = 'X';
	flood_fill(game, i - 1, j, rows);
	flood_fill(game, i + 1, j, rows);
	flood_fill(game, i, j - 1, rows);
	flood_fill(game, i, j + 1, rows);
}

/**
 * Validates that the map is fully enclosed by walls.
 * Calls flood_fill for each empty space.
 * error if it detects an area not enclosed.
 */
void	validate_walls(t_game *game)
{
	int	len;
	int	rows;
	int	j;
	int	i;

	rows = 0;
	while (game->map[rows])
		rows++;
	i = 0;
	while (i < rows)
	{
		j = 0;
		len = ft_strlen(game->map[i]);
		while (j < len)
		{
			if (game->map[i][j] == '0')
				flood_fill(game, i, j, rows);
			j++;
		}
		i++;
	}
}
