#include "parser.h"

static char	**copy_map(t_game *game, int rows)
{
	int		i;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		ft_error_msg("error malloc copy_map", game);
	i = 0;
	while (i < rows)
	{
		new_map[i] = ft_strdup(game->map[i]);
		if (!new_map[i])
			ft_error_msg("Malloc error in copy_map row", game);
		i++;
	}
	new_map[rows] = NULL;
	return (new_map);
}

static void	flood_fill_spaces(t_game *game, int i, int j, int rows)
{
	if (i < 0 || i >= rows || j < 0 || j >= (int)ft_strlen(game->aux_map[i]))
		return ;
	if (game->aux_map[i][j] == '0' || game->aux_map[i][j] == 'X')
		ft_error_msg("hole in map", game);
	if (game->aux_map[i][j] == '1' || game->aux_map[i][j] == 'v')
		return ;
	game->aux_map[i][j] = 'v';
	flood_fill_spaces(game, i - 1, j, rows);
	flood_fill_spaces(game, i + 1, j, rows);
	flood_fill_spaces(game, i, j - 1, rows);
	flood_fill_spaces(game, i, j + 1, rows);
}

static void	flood_fill(t_game *game, int i, int j, int rows)
{
	if (i < 0 || i >= rows || j < 0 || j >= (int)ft_strlen(game->aux_map[i]))
		ft_error_msg("mapa not delimied", game);
	if (game->aux_map[i][j] == '1' || game->aux_map[i][j] == 'X'
		|| game->aux_map[i][j] == ' ' || game->aux_map[i][j] == 'v')
		return ;
	game->aux_map[i][j] = 'X';
	flood_fill(game, i - 1, j, rows);
	flood_fill(game, i + 1, j, rows);
	flood_fill(game, i, j - 1, rows);
	flood_fill(game, i, j + 1, rows);
}

void	validate_walls(t_game *game)
{
	int	len;
	int	rows;
	int	j;
	int	i;

	rows = 0;
	while (game->map[rows])
		rows++;
	game->aux_map = copy_map(game, rows);
	i = 0;
	while (i < rows)
	{
		j = 0;
		len = ft_strlen(game->aux_map[i]);
		while (j < len)
		{
			if (game->aux_map[i][j] == '0')
				flood_fill(game, i, j, rows);
			else if (game->aux_map[i][j] == ' ')
				flood_fill_spaces(game, i, j, rows);
			j++;
		}
		i++;
	}
}
