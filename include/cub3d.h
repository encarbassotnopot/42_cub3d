#ifndef CUB3D_H
# define CUB3D_H
# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 512
# define HEIGHT 512
# include "mathematics.h"

typedef struct s_player
{
	t_vec2		pos;
	t_vec2		dir;
}				t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	char		**map;
	t_player	player;
}				t_game;

#endif