
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("error args\n"), -1);
	init_structs(&game);
	init_map(argv[1], &game);
	run_mlx(&game);
	free_strucs(&game);
	return (0);
}
