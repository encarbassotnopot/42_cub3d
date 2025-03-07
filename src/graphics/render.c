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
	int		x;
	int		y;
	char	face;

	face = 0;
	x = floorf(point->i);
	y = floorf(point->j);
	if ((float)x == point->i)
	{
		face = 'W';
		if (cosf(angle) < 0)
		{
			face = 'E';
			x--;
		}
	}
	if ((float)y == point->j)
	{
		face = 'N';
		if (sinf(angle) < 0)
		{
			face = 'S';
			y--;
		}
	}
	if (face == 0)
		printf("ray hit at %f, %f with angle %f\n", point->i, point->j, angle
			* 180 / M_PI);
	if (y > game->map_height || y < 0)
		return (0);
	if (x > game->row_len[y] || x < 0)
		return (0);
	if (game->map[x][y] == '1')
		return (face);
	return (game->map[x][y]);
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
 * Renders a vertical strip of wall from it's distance.
 */
void	draw_wall(t_game *game, float dist, int x, char face)
{
	int			y;
	int			height;
	uint32_t	color;

	if (face == 'N')
		color = 0xFFFFFF;
	else if (face == 'S')
		color = 0xFFFF00FF;
	else if (face == 'W')
		color = 0xFF00FF;
	else if (face == 'E')
		color = 0xFF0000FF;
	else
		color = 0xFF;
	y = -1;
	height = 1 / dist * HEIGHT;
	while (++y < HEIGHT)
	{
		if (y < HEIGHT / 2 - height / 2)
			mlx_put_pixel(game->img, x, y, 0xFFFF);
		else if (y < height / 2 + HEIGHT / 2)
			mlx_put_pixel(game->img, x, y, color);
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
	t_vec2	ray;
	float	dist;
	char	face;

	x = -1;
	angle = game->player.dir - FOV / 2;
	while (++x < WIDTH)
	{
		ray = (t_vec2){game->player.pos.i, game->player.pos.j};
		face = raycast(game, &ray, angle);
		if (face)
		{
			dist = abs_vec(subt_from_vec(&ray, &game->player.pos));
			draw_wall(game, dist, x, face);
		}
		else
			draw_oob(game, x);
		angle += FOV / WIDTH;
	}
}
