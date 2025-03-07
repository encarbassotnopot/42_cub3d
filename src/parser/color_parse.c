#include "parser.h"

/*
color_parse(line, game);
{
	int flag_f;
	char **values;
	int i;

	i = 0;
	flag = 0;
	while (ft_isspace(*line))
		line++;
	if (*line == 'F')
		flag = 1;
	line++;
	while (ft_isspace(*line))
		line++;
	values = ft_split(line, ',');
	if (values)
	{
		while (values[i])
			i++;
		if (i != 3)
			ft_error_msg("must be 3 colors\n");
		i = 0;
		while (i < 3)
		{
			if (strchr(values[i], ' '))
				values[i] = remove_spaces(values[i]);
			i++;
		}
	}
}*/