#include "cub3d.h"

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_mov_key_hook(mlx_key_data_t keydata, t_game *game)
{
	float	mov_speed;

	mov_speed = 0.05;
	if (keydata.key == MLX_KEY_W)
	{
		game->player.pos.i += cos(game->player.dir) * mov_speed;
		game->player.pos.j += sin(game->player.dir) * mov_speed;
	}
	else if (keydata.key == MLX_KEY_S)
	{
		game->player.pos.i -= cos(game->player.dir) * mov_speed;
		game->player.pos.j -= sin(game->player.dir) * mov_speed;
	}
	else if (keydata.key == MLX_KEY_A)
	{
		game->player.pos.i -= cos(game->player.dir + M_PI / 2) * mov_speed;
		game->player.pos.j -= sin(game->player.dir + M_PI / 2) * mov_speed;
	}
	else if (keydata.key == MLX_KEY_D)
	{
		game->player.pos.i += cos(game->player.dir + M_PI / 2) * mov_speed;
		game->player.pos.j += sin(game->player.dir + M_PI / 2) * mov_speed;
	}
	printf("Player position: (%f, %f)\n", game->player.pos.i,
		game->player.pos.j);
}

void	ft_rot_key_hook(mlx_key_data_t keydata, t_game *game)
{
	float	rot_speed;

	rot_speed = M_PI / 90;
	if (keydata.key == MLX_KEY_LEFT)
		game->player.dir -= rot_speed;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->player.dir += rot_speed;
	printf("Player direction: %F\n", game->player.dir * 180 / M_PI);
}

void	ft_key_hook(mlx_key_data_t keydata, t_game *game)
{
	printf("key: %d\n", keydata.key);
	if (ft_isascii(keydata.key))
		ft_mov_key_hook(keydata, game);
	else
		ft_rot_key_hook(keydata, game);
	render_scene(game);
}

int32_t	run_mlx(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!game->mlx)
		ft_error();
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
		ft_error();
	mlx_key_hook(game->mlx, (mlx_keyfunc)ft_key_hook, game);
	render_scene(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
