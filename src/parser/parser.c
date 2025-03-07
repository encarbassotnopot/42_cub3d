#include "parser.h"

static char	*find_init_end_path(char *line, t_game *game)
{
	int		i;
	int		j;
	char	*path_start;
	char	*path;
	int		fd;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (line[i])
		path_start = &line[i];
	j = i;
	while (line[j] && !ft_isspace(line[j]))
		j++;
	line[j] = '\0';
	path = ft_strdup(path_start);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		ft_error_msg("error en img path", game);
	}
	close(fd);
	return (path);
}

static void	fill_info(char *line, t_game *game)
{
	while (ft_isspace(*line))
		line++;
	if (!ft_strncmp(line, "NO", 2))
		game->info.no = find_init_end_path(line, game);
	else if (!ft_strncmp(line, "SO", 2))
		game->info.so = find_init_end_path(line, game);
	else if (!ft_strncmp(line, "EA", 2))
		game->info.ea = find_init_end_path(line, game);
	else if (!ft_strncmp(line, "WE", 2))
		game->info.we = find_init_end_path(line, game);
	else if (!ft_strncmp(line, "F", 1) || (!ft_strncmp(line, "C", 1)))
		printf("falta color_parse(line, game);\n");
	else
		ft_error_msg("Error info configuration", game);
}

static void	fill_map(char **joined_lines, char *line)
{
	char	*temp;

	temp = ft_strjoin(*joined_lines, line);
	free(*joined_lines);
	*joined_lines = temp;
}

static void	create_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*joined_lines;

	fd = open_file(file, game);
	joined_lines = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (is_map(line))
			fill_map(&joined_lines, line);
		else
			fill_info(line, game);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = ft_split(joined_lines, '\n');
	free(joined_lines);
}

void	init_map(char *file, t_game *game)
{
	if (!file)
		ft_error_msg("error file", game);
	if (ft_strncmp(file + (ft_strlen(file) - 4), ".cub", 4) != 0)
		ft_error_msg("wrong file extension", game);
	init_structs(game);
	create_map(file, game);
	validate_map(game);
	calc_map_size(game);
	validate_info(game);
	validate_walls(game);
}
