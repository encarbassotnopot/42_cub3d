
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
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
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
	game->info.floor = NULL;
	game->info.ceiling = NULL;
	game->map = NULL;
	game->aux_map = NULL;
}
