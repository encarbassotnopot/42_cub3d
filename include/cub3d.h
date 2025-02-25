

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**mapa;
	int		p_pos_y;
	int		p_pos_x;
}			t_map;

typedef struct s_game
{
	// void	*mlx;
	t_map	*map;
	//	t_img	*img;
}			t_game;

#endif