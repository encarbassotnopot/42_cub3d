
#include "cub3d.h"

void	ft_error_msg(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("error args\n"), -1);
	init_map(argv[1], &game);
	debug_info(&game.info);
	debug_map(game.map);
	return (0);
}
