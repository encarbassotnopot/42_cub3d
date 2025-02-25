
#include "cub3d.h"

void	ft_error_msg(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

void	create_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*joined_lines;

	line = "";
	joined_lines = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(joined_lines);
		ft_error_msg("open file error");
	}
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		joined_lines = ft_strjoin(joined_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	game->map->mapa = ft_split(joined_lines, '\n');
	free(joined_lines);
}

void	init_map(char *file, t_game *game)
{
	char	*result;

	if (!file)
		ft_error_msg("invalid file");
	result = ft_strnstr(file, ".cub", ft_strlen(file));
	if (result == NULL)
		ft_error_msg("Error extension");
	if (ft_strncmp(result, ".cub", 3) != 0)
		ft_error_msg("error extension");
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_error_msg("error al crear el map");
		exit(-1);
	}
	game->map->mapa = NULL;
	create_map(file, game);
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (printf("error args\n"), -1);
	init_map(argv[1], &game);
}