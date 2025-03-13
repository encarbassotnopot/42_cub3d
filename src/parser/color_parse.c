#include "parser.h"

uint32_t	parse_color(char *line, t_game *game)
{
	int	red;
	int	green;
	int	blue;

	while (*line && ft_isspace(*line))
		line++;
	red = ft_atoi(line);
	while ((*line && ft_isspace(*line)) || (*line && *line == ','))
		line++;
	green = ft_atoi(line);
	while ((*line && ft_isspace(*line)) || (*line && *line == ','))
		line++;
	blue = ft_atoi(line);
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0
		|| blue > 255)
		ft_error_msg("Invalid color value", game);
	return (((0xFF << 24) | (red << 16) | (green << 8) | blue));
}
