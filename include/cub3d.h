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
}				t_game;
void			find_next_edge(t_game *game, t_vec2 *current);

#endif