#ifndef STRUCTS_H
# define STRUCTS_H
# include "cub3d.h"

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

#endif