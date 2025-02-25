#include "cub3d.h"

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void	ft_hook(void *game)
{
	mlx_t	*mlx;

	mlx = ((t_game *)game)->mlx;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
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
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
