/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:32:05 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/03/13 13:30:28 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * Checks that all textures (NO, SO, WE,
 * 	EA) are present in the game's information structure.
 * If any of them are missing, it displays an error message.
 */
void	validate_info(t_game *game)
{
	if (!game->info.no || !game->info.so || !game->info.we || !game->info.ea)
		ft_error_msg("Error, missing textures(NO, SO, WE, EA).", game);
	if (!game->info.floor || !game->info.ceiling)
		ft_error_msg("Error, missing colors.", game);
}

/**
 * Calculates the map's size and records it in game
 */
void	calc_map_size(t_game *game)
{
	int	i;

	while (game->map[game->map_height])
		game->map_height++;
	game->row_len = ft_calloc(game->map_height + 1, sizeof(int));
	i = -1;
	while (game->map[++i])
		game->row_len[i] = ft_strlen(game->map[i]);
}

/**
 * Checks that the map specifications (1 player,
 * and only allowed characters: "01 ").
 */
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
			if (setup_player(game, i, j, game->map[i][j]))
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
