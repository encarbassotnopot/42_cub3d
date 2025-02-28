
#include "parser.h"

int	open_file(char *file, t_game *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_msg("open file error", game);
	return (fd);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (0);
	while (line[i] != '\n')
	{
		if (!ft_strchr("01NSEW ", line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	init_structs(t_game *game)
{
	game->info.no = NULL;
	game->info.so = NULL;
	game->info.we = NULL;
	game->info.ea = NULL;
	game->info.floor = 0xFFFFFFFF;
	game->info.ceiling = 0xFFFF;
	game->map = NULL;
	game->map_height = 0;
	game->row_len = NULL;
}
