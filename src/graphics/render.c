#include "cub3d.h"
#include "render.h"

/**
 * Finds the next intersection with an edge in the given direction
 */
void	find_next_edge(t_vec2 *current, float angle)
{
	t_vec2	dest;
	t_vec2	steps;

	// finds the closest edge in each direction.
	if (cosf(angle) > 0)
		dest.i = floorf(current->i + 1);
	else
		dest.i = ceilf(current->i - 1);
	if (sinf(angle) > 0)
		dest.j = floorf(current->j + 1);
	else
		dest.j = ceilf(current->j - 1);
	// calculates how far away we are from each edge.
	if (!cosf(angle))
		steps.i = 10000;
	else
		steps.i = (dest.i - current->i) / cosf(angle);
	if (!sinf(angle))
		steps.j = 10000;
	else
		steps.j = (dest.j - current->j) / sinf(angle);
	// update the current position
	current->i += cosf(angle) * fmin(steps.i, steps.j);
	current->j += sinf(angle) * fmin(steps.i, steps.j);
}

/**
 * Returns the map element (char) found at a given point (edge),
 * taking into account from which edge you have hit it.
 */
char	get_map_element(t_game *game, t_vec2 *point, float angle)
{
	int		x;
	int		y;
	char	face;

	face = 1;
	x = floorf(point->i) - 1;
	y = floorf(point->j) - 1;
	if ((float)x + 1 == point->i)
	{
		face = 'W';
		if (cosf(angle) < 0)
		{
			face = 'E';
			x--;
		}
	}
	if ((float)y + 1 == point->j)
	{
		face = 'N';
		if (sinf(angle) < 0)
		{
			face = 'S';
			y--;
		}
	}
	if (y > game->map_height || y < 0)
		return (0);
	if (x > game->row_len[y] || x < 0)
		return (0);
	if (game->map[y][x] == '1')
		return (face);
	return (game->map[y][x]);
}

/**
 * Propagates the given ray it until an edge is hit or out of bounds.
 * Returns which face has been het if an edge is found, 0 otherwise.
 */
char	raycast(t_game *game, t_vec2 *ray, float angle)
{
	find_next_edge(ray, angle);
	while (get_map_element(game, ray, angle) == 'X')
		find_next_edge(ray, angle);
	return (get_map_element(game, ray, angle));
}

/**
 * Well, renders the scene.
 */
void	render_scene(t_game *game)
{
	int		x;
	t_vec2	ray;
	float	dist;
	char	face;

	x = -1;
	while (++x < WIDTH)
	{
		ray = (t_vec2){game->player.pos.i, game->player.pos.j};
		face = raycast(game, &ray, angle_from_x(x) + game->player.dir);
		if (face)
		{
			dist = abs_vec(subt_from_vec(&ray, &game->player.pos));
			draw_wall(game, dist, x, face);
		}
		else
			draw_oob(game, x);
	}
}
