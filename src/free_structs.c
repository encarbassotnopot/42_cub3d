
#include "parser.h"

static void	free_infos(t_info *info)
{
	if (info->no)
		free(info->no);
	if (info->so)
		free(info->so);
	if (info->we)
		free(info->we);
	if (info->ea)
		free(info->ea);
	if (info->ceiling)
		free(info->ceiling);
	if (info->floor)
		free(info->floor);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !(map[i]))
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
		if (!map[i])
			return ;
	}
}

void	ft_error_msg(char *str, t_game *game)
{
	free_strucs(game);
	printf("%s\n", str);
	exit(-1);
}
void	free_strucs(t_game *game)
{
	if (game->map)
	{
		ft_free_map(game->map);
		free(game->map);
	}
	if (game->aux_map)
	{
		ft_free_map(game->aux_map);
		free(game->aux_map);
	}
	free_infos(&game->info);
}
