/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strucs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:32:05 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/03/13 12:32:34 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Opens a file and returns the file descriptor.
 * If an error occurs, it shows an error message.
 */
int	open_file(char *file, t_game *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_msg("open file error", game);
	return (fd);
}

/**
 * Checks if the given charachter represents the player.
 * If it does, it records the player's info
 * (starting point and direction) and returns 1.
 * Otherwise, it returns 0.
 */
int	setup_player(t_game *game, int x, int y, char c)
{
	if (!ft_strchr("NSWE", c))
		return (0);
	game->player.pos = (t_vec2){.i = y + 0.5, .j = x + 0.5};
	if (c == 'E')
		game->player.dir = 0;
	else if (c == 'S')
		game->player.dir = M_PI_2;
	else if (c == 'W')
		game->player.dir = M_PI;
	else if (c == 'N')
		game->player.dir = M_PI + M_PI_2;
	return (1);
}

/**
 * Checks if the line is part of the map.
 * Returns 1 if valid, 0 otherwise.
 */
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
		if (!ft_strchr("01NSEW ", line[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Initializes game structures with default values.
 */
void	init_structs(t_game *game)
{
	int	i;

	game->info.no = NULL;
	game->info.so = NULL;
	game->info.we = NULL;
	game->info.ea = NULL;
	game->info.floor = 0;
	game->info.ceiling = 0;
	game->map = NULL;
	game->map_height = 0;
	game->row_len = NULL;
	game->mlx = NULL;
	game->img = NULL;
	i = -1;
	while (++i < 4)
		game->walls[i] = NULL;
}
