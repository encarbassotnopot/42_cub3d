#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_info
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	uint32_t	ceiling;
	uint32_t	floor;
}				t_info;

typedef struct s_game
{
	char		**map;
	int			map_height;
	int			*row_len;
	t_info		info;
}				t_game;

void			ft_error_msg(char *str, t_game *game);
void			free_strucs(t_game *game);
void			ft_free_map(char **map);
void			debug_info(t_info *info);
void			init_map(char *file, t_game *game);
#endif