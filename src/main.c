
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("error args\n"), -1);
	init_map(argv[1], &game);
	debug_info(&game.info);
	debug_map(game.map);
	run_mlx(&game);
	free_strucs(&game);
	return (0);
}
