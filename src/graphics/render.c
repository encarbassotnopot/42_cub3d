#include "cub3d.h"

/**
 * Finds the next edge
 */
void	find_next_edge(t_game *game, t_vec2 *current)
{
	t_vec2	dest;
	t_vec2	steps;

	// finds the closest edge in each direction.
	if (cosf(game->player.dir) > 0)
		dest.i = floorf(current->i + 1);
	else
		dest.i = ceilf(current->i - 1);
	if (sinf(game->player.dir) > 0)
		dest.j = floorf(current->j + 1);
	else
		dest.j = ceilf(current->j - 1);
	// calculates how far away we are from each edge.
	if (!cosf(game->player.dir))
		steps.i = 10000;
	else
		steps.i = (dest.i - current->i) / cosf(game->player.dir);
	if (!sinf(game->player.dir))
		steps.j = 10000;
	else
		steps.j = (dest.j - current->j) / sinf(game->player.dir);
	// update the current position
	current->i += cosf(game->player.dir) * fmin(steps.i, steps.j);
	current->j += sinf(game->player.dir) * fmin(steps.i, steps.j);
	printf("Found edge: (%f, %f)\n", current->i, current->j);
}

char	get_map_element(t_game *game, t_vec2 *point, float angle)
{
	int	x;
	int	y;

	x = floorf(point->i);
	y = floorf(point->j);
	if (cosf(angle) < 0 && (float)x == point->i)
		x--;
	if (sinf(angle) < 0 && (float)y == point->j)
		y--;
	return (game->map[x][y]);
}

void	raycast(t_game *game, int x)
{
	t_vec2	ray;
	t_vec2	next_edge;
	int		count;

	ray = (t_vec2){game->player.pos.i, game->player.pos.j};
	find_next_edge(game, &ray);
	while (get_map_element(game, &ray, game->player.dir) != '1')
		find_next_edge(game, &ray);
	printf("Next edge: (%f, %f)\n", ray.i, ray.j);
	mlx_put_pixel(game->img, ray.i * WIDTH / 7, ray.j * HEIGHT / 7, 0xFF0000FF);
}

void	render_scene(t_game *game)
{
	int	x;

	x = -1;
	// while (++x < WIDTH)
	//	raycast(game, x);
	raycast(game, 0);
}
