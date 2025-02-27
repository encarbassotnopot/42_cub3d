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
		dest.i = ceilf(current->i);
	else
		dest.i = floorf(current->i);
	if (sinf(game->player.dir) > 0)
		dest.j = ceilf(current->j);
	else
		dest.j = floorf(current->j);
	// calculates how far away we are from each edge.
	if (!cosf(game->player.dir))
		steps.i = 2;
	else
		steps.i = (dest.i - current->i) / cosf(game->player.dir);
	if (!sinf(game->player.dir))
		steps.j = 2;
	else
		steps.j = (dest.j - current->j) / sinf(game->player.dir);
	// update the current position
	current->i += cosf(game->player.dir) * fmin(steps.i, steps.j);
	current->j += sinf(game->player.dir) * fmin(steps.i, steps.j);
	printf("Found edge: (%f, %f)\n", current->i, current->j);
}

void	raycast(t_game *game, int x)
{
	t_vec2	ray;
	t_vec2	next_edge;

	ray = (t_vec2){game->player.pos.i, game->player.pos.j};
	find_next_edge(game, &ray);
//	while (game->map[(int)ray.i][(int)ray.j] != '1' && ray.i > -1 && ray.j > -1
//		&& ray.i < 6 && ray.j < 6)
		find_next_edge(game, &ray);
	printf("Next edge: (%f, %f)\n", ray.i, ray.j);
}

void	render_scene(t_game *game)
{
	int	x;

	x = -1;
	// while (++x < WIDTH)
	//	raycast(game, x);
	raycast(game, 0);
}
