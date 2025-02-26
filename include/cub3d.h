

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct s_info
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*ceiling;
	char	*floor;
}			t_info;

typedef struct s_map
{
	char	**mapa;
	int		player_count;
}			t_map;

typedef struct s_game
{
	// void	*mlx;
	t_map	*map;
	t_info	info;
	//	t_img	*img;
}			t_game;

void		ft_error_msg(char *str);
int			is_player(char c);
void		init_map(char *file, t_game *game);
int			is_map(char *line);
void		init_structs(t_game *game);

// validaters:
void		validate_map(t_game *game);
void		validate_info(t_game *game);
// void	validate_walls(t_game *game);

char		*get_next_line(int fd);

// debugers:
void		debug_map(t_map *map);
void		debug_info(t_info *info);

#endif