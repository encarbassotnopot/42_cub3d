/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:32:18 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/03/13 12:32:18 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

// inits
void		init_structs(t_game *game);

// validaters:
void		validate_map(t_game *game);
void		validate_info(t_game *game);
void		validate_walls(t_game *game);
void		calc_map_size(t_game *game);

// auxiliars
char		*get_next_line(int fd);
int			open_file(char *file, t_game *game);
int			is_map(char *line);
int			setup_player(t_game *game, int x, int y, char c);
uint32_t	parse_color(char *line, t_game *game);

// debugers:
void		debug_map(char **mapa);
void		printmap(t_game *game);
void		print_playerpos(t_game *game);

#endif
