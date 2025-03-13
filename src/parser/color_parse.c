#include "parser.h"

uint32_t	parse_color(char *line, t_game *game)
{
	int	red;
	int	green;
	int	blue;

	while (ft_isspace(*line))
		line++;
	red = ft_raw_atoi_fwd(&line);
	while ((ft_isspace(*line)) || (*line == ','))
		line++;
	green = ft_raw_atoi_fwd(&line);
	while ((ft_isspace(*line)) || (*line == ','))
		line++;
	blue = ft_raw_atoi_fwd(&line);
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0
		|| blue > 255)
		ft_error_msg("Invalid color value", game);
	printf("red: %d, green: %d, blue: %d\n", red, green, blue);
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}
