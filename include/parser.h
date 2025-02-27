#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

// inits

void	init_structs(t_game *game);

// validaters:
void	validate_map(t_game *game);
void	validate_info(t_game *game);
void	validate_walls(t_game *game);
void	validate_walls(t_game *game);

// auxiliars
char	*get_next_line(int fd);
int		open_file(char *file, t_game *game);
int		is_map(char *line);
int		is_player(char c);

// debugers:
void	debug_map(char **mapa);

#endif