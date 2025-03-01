#include "cub3d.h"

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
	int	x;
	int	y;

	x = floorf(point->i);
	y = floorf(point->j);
	if (cosf(angle) < 0 && (float)x == point->i)
		x--;
	if (sinf(angle) < 0 && (float)y == point->j)
		y--;
	if (y > game->map_height || y < 0)
		return (0);
	if (x > game->row_len[y] || x < 0)
		return (0);
	return (game->map[x][y]);
}

/**
 * Propagates the given ray it until an edge is hit or out of bounds.
 * Returns 1 if an edge is hit, 0 otherwise.
 */
int	raycast(t_game *game, t_vec2 *ray, float angle)
{
	find_next_edge(ray, angle);
	while (get_map_element(game, ray, angle) == 'X')
		find_next_edge(ray, angle);
	if (get_map_element(game, ray, angle) == '1')
		return (1);
	return (0);
}

/**
 * Renders a vertical strip of wall from it's distance.
 */
void	draw_wall(t_game *game, float dist, int x, float angle)
{
	int	y;
	int	height;

	y = -1;
	height = 1 / dist * HEIGHT;
	while (++y < HEIGHT)
	{
		printf("drawing wall at %d, %d\n", x, y);
		if (y < HEIGHT / 2 - height / 2)
			mlx_put_pixel(game->img, x, y, 0xFFFF);
		else if (y < height / 2 + HEIGHT / 2)
			mlx_put_pixel(game->img, x, y, 0xFF00FF);
		else
			mlx_put_pixel(game->img, x, y, 0xFFFFFFFF);
	}
}

/**
 * Renders a vertical strip of nothingness, as we are rendering out of bounds.
 */
void	draw_oob(t_game *game, int x)
{
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		printf("drawing oob at %d, %d\n", x, y);
		mlx_put_pixel(game->img, x, y, 0xFF00FFFF);
	}
}

/**
 * Well, renders the scene.
 */
void	render_scene(t_game *game)
{
	int		x;
	float	angle;
	float	step;
	t_vec2	ray;
	float	dist;

	x = -1;
	angle = game->player.dir - FOV / 2;
	step = FOV / WIDTH;
	while (++x < WIDTH)
	{
		printf("casting ray at x %d\n", x);
		printf("ray starting at %f,%f\n", game->player.pos.i,
			game->player.pos.j);
		printf("angle is %f\n", angle * 180 / M_PI);
		ray = (t_vec2){game->player.pos.i, game->player.pos.j};
		if (raycast(game, &ray, angle))
		{
			dist = abs_vec(subt_from_vec(&ray, &game->player.pos));
			draw_wall(game, dist, x, angle);
		}
		else
			draw_oob(game, x);
		angle += step;
	}
}
