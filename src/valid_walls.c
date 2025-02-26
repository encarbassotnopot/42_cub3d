#include "cub3d.h"

static char	**copy_map(char **map, int rows)
{
	int		i;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		ft_error_msg("error malloc copy_map");
	i = 0;
	while (i < rows)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
			ft_error_msg("Malloc error in copy_map row");
		i++;
	}
	new_map[rows] = NULL;
	return (new_map);
}

static void	flood_fill(char **aux_map, int i, int j, int rows, int cols)
{
	if (i < 0 || i >= rows || j < 0 || aux_map[i][j] == ' ')
		return ;
	cols = ft_strlen(aux_map[i]);
	if (j >= cols)
		return ;
	if (aux_map[i][j] == '-')
	{
		aux_map[i][j] = 'v';
		flood_fill(aux_map, i - 1, j, rows, cols); // puja una fila
		flood_fill(aux_map, i + 1, j, rows, cols); // baixa una fila
		flood_fill(aux_map, i, j - 1, rows, cols); // va a esquerra
		flood_fill(aux_map, i, j + 1, rows, cols); // va a la dreta
	}
}

static void	bucle_for_valid_walls(char **aux_map, int rows, int len)
{
	int	j;
	int	i;

	i = 0;
	while (i < rows)
	{
		j = 0;
		len = ft_strlen(aux_map[i]);
		while (j < len)
		{
			if (aux_map[i][j] == '-')
				ft_error_msg("fallo flood-fill");
			if (aux_map[i][j] == ' ')
			{
				if ((aux_map[i - 1][j] && (aux_map[i - 1][j] != '1'))
					|| (aux_map[i + 1][j] && (aux_map[i + 1][j] != '1'))
					|| (aux_map[i][j - 1] && (aux_map[i][j - 1] != '1'))
					|| (aux_map[i][j + 1] && (aux_map[i][j + 1] != '1')))
					ft_error_msg("error space map");
			}
			j++;
		}
		i++;
	}
}

void	validate_walls(t_game *game)
{
	int		len;
	int		rows;
	char	**aux_map;

	rows = 0;
	while (game->map->mapa[rows])
		rows++;
	len = ft_strlen(game->map->mapa[0]);
	aux_map = copy_map(game->map->mapa, rows);
	flood_fill(aux_map, 0, 0, rows, len);
	bucle_for_valid_walls(aux_map, rows, len);
}
