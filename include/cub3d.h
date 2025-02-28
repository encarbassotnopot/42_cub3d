#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include "mathematics.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 512
# define HEIGHT 512
# define FOV M_PI_2

typedef struct s_info
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	uint32_t	ceiling;
	uint32_t	floor;
}				t_info;

typedef struct s_player
{
	t_vec2		pos;
	float		dir;
}				t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	char		**map;
	t_player	player;
	mlx_image_t	*img;
	int			map_height;
	int			*row_len;
	t_info		info;
}				t_game;

void			render_scene(t_game *game);
void			ft_error_msg(char *str, t_game *game);
void			free_strucs(t_game *game);
void			ft_free_map(char **map);
void			debug_info(t_info *info);
void			init_map(char *file, t_game *game);
int32_t			run_mlx(t_game *game);
#endif
