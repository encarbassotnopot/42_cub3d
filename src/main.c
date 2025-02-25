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
		game->player.pos.i += cos(game->player.dir.i) * mov_speed;
		game->player.pos.j += sin(game->player.dir.i) * mov_speed;
	}
	else if (keydata.key == MLX_KEY_S)
	{
		game->player.pos.i -= cos(game->player.dir.i) * mov_speed;
		game->player.pos.j -= sin(game->player.dir.i) * mov_speed;
	}
	else if (keydata.key == MLX_KEY_A)
	{
		game->player.pos.i -= cos(game->player.dir.i + M_PI / 2) * mov_speed;
		game->player.pos.j -= sin(game->player.dir.i + M_PI / 2) * mov_speed;
	}
	else if (keydata.key == MLX_KEY_D)
	{
		game->player.pos.i += cos(game->player.dir.i + M_PI / 2) * mov_speed;
		game->player.pos.j += sin(game->player.dir.i + M_PI / 2) * mov_speed;
	}
	printf("Player position: (%f, %f)\n", game->player.pos.i,
		game->player.pos.j);
}

void	ft_rot_key_hook(mlx_key_data_t keydata, t_game *game)
{
	float	rot_speed;

	rot_speed = M_PI / 100;
	if (keydata.key == MLX_KEY_LEFT)
		game->player.dir.i -= rot_speed;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->player.dir.i += rot_speed;
	else if (keydata.key == MLX_KEY_UP)
		game->player.dir.j -= rot_speed;
	else if (keydata.key == MLX_KEY_DOWN)
		game->player.dir.j += rot_speed;
	printf("Player direction: (%f, %f)\n", game->player.dir.i,
		game->player.dir.j);
}

void	ft_key_hook(mlx_key_data_t keydata, t_game *game)
{
	printf("key: %d\n", keydata.key);
	if (ft_isascii(keydata.key))
		ft_mov_key_hook(keydata, game);
	else
		ft_rot_key_hook(keydata, game);
}

int32_t	main(void)
{
	t_game		game;
	mlx_image_t	*img;

	game.map = (char *[6]){"11111", "10001", "10101", "10001", "11111", NULL};
	game.player.pos = (t_vec2){0.5, 0.5};
	game.player.dir = (t_vec2){0, M_PI};
	game.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!game.mlx)
		ft_error();
	img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(game.mlx, img, 0, 0) < 0))
		ft_error();
	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_key_hook(game.mlx, ft_key_hook, &game);
	mlx_key_hook(game.mlx, ft_key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
