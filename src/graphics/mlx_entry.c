#include "cub3d.h"

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
	game->player.dir += M_PI * 2;
	game->player.dir = fmod(game->player.dir, M_PI * 2);
	printf("Player direction: %F\n", game->player.dir * 180 / M_PI);
}

void	ft_key_hook(mlx_key_data_t keydata, t_game *game)
{
	if (ft_isascii(keydata.key))
		ft_mov_key_hook(keydata, game);
	else
		ft_rot_key_hook(keydata, game);
	render_scene(game);
}

void	load_images(t_game *game)
{
	const char		*paths[4] = {game->info.no, game->info.so, game->info.ea,
				game->info.we};
	mlx_texture_t	*texture;
	int				i;

	i = -1;
	while (++i < 4)
	{
		if (ft_strlen(paths[i]) >= 4 && ft_strcmp(paths[i]
				+ (ft_strlen(paths[i]) - 4), ".png") == 0)
			texture = mlx_load_png(paths[i]);
		else
			ft_error_msg("Invalid texture path\n", game);
		if (!texture)
			ft_error_msg("Error opening texture\n", game);
		game->walls[i] = mlx_texture_to_image(game->mlx, texture);
		if (!game->walls[i])
			ft_error_msg("Error creating image\n", game);
	}
}

int32_t	run_mlx(t_game *game)
{
	game->player.pos.i++;
	game->player.pos.j++;
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!game->mlx)
		ft_error_msg("Error initialising mlx", game);
	load_images(game);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
		ft_error_msg("Error creating game image", game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)ft_key_hook, game);
	render_scene(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
