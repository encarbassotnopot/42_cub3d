#include "parser.h"

/**

	* Skips the spaces to find the exact image path and checks that it exists before proceeding.
 */
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
/**
 * Analyzes the start of the line, skipping spaces,
 * 	and writes the corresponding info.
 * If it doesn't recognize anything, it raises an error.
 */
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
	else if (!ft_strncmp(line, "C", 1))
		game->info.ceiling = parse_color(line + 1, game);
	else if (!ft_strncmp(line, "F", 1))
		game->info.floor = parse_color(line + 1, game);
	else
		ft_error_msg("Error info configuration", game);
}
/**
 * While the line is part of the map, it joins it into joined_lines.
 * If there is extra content at the end, it raises an error.
 * Once the map is finished or a '\n' is encountered,
 * 	it performs a split to create game->map.
 */
static void	fill_map(char *line, int fd, t_game *game)
{
	char	*temp;
	char	*joined_lines;

	joined_lines = ft_strdup("");
	while (line && is_map(line))
	{
		temp = ft_strjoin(joined_lines, line);
		free(joined_lines);
		joined_lines = temp;
		free(line);
		line = get_next_line(fd);
	}
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line && line[0] != '\0')
	{
		free(line);
		ft_error_msg("error map in file", game);
	}
	game->map = ft_split(joined_lines, '\n');
	free(joined_lines);
}
/**
 * Opens the file and processes each line according to whether it is a map,
 * 	info, or '\n'.
 */
static void	create_map(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open_file(file, game);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line))
		{
			fill_map(line, fd, game);
			break ;
		}
		else if (line[0] != '\n')
			fill_info(line, game);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
/**
 * Initializes t_game and validate inputs.
 */
void	init_map(char *file, t_game *game)
{
	if (!file)
		ft_error_msg("error file", game);
	if (ft_strlen(file) >= 4 && ft_strncmp(file + (ft_strlen(file) - 4), ".cub",
			4) != 0)
		ft_error_msg("wrong file extension", game);
	create_map(file, game);
	validate_map(game);
	calc_map_size(game);
	validate_info(game);
	validate_walls(game);
}
