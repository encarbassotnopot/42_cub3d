#include "cub3d.h"
#include "render.h"

/**
 * Returns which color should be painted according to where a ray has
 * hit a wall.
 * Impact's coordinates are in relation to the wall, not the map. They must be
 * in the range [0,1).
 */
uint32_t	get_wall_pixel(t_game *game, t_vec2 *impact, char orientation)
{
	mlx_image_t	*wall;
	int			x;
	int			y;

	if (orientation == 'N')
		wall = game->walls[NORTH];
	else if (orientation == 'S')
		wall = game->walls[SOUTH];
	else if (orientation == 'W')
		wall = game->walls[WEAST];
	else
		wall = game->walls[EAST];
	x = fmin(impact->i * wall->width, wall->width - 1);
	y = fmin(impact->j * wall->height, wall->height - 1);
	return (((uint32_t *)wall->pixels)[y * wall->width + x]);
}

/**
 * Renders a vertical strip of wall from it's distance.
 */
void	draw_wall(t_game *game, t_vec2 *ray, int x, char face)
{
	int		y;
	float	view;
	float	dist;
	float	step;
	t_vec2	impact;

	if (face == 'N' || face == 'S')
		impact.i = ray->i - (int)ray->i;
	else
		impact.i = ray->j - (int)ray->j;
	dist = abs_vec(subt_from_vec(ray, &game->player.pos));
	y = -1;
	view = HEIGHT / dist / cosf(angle_from_x(x));
	step = 1 / view;
	impact.j = (-HEIGHT + view) / 2 * step;
	while (++y < HEIGHT)
	{
		if (y < (HEIGHT - view) / 2)
			mlx_put_pixel(game->img, x, y, game->info.ceiling);
		else if (y < (HEIGHT + view) / 2)
			mlx_put_pixel(game->img, x, y, get_wall_pixel(game, &impact, face));
		else
			mlx_put_pixel(game->img, x, y, game->info.floor);
		impact.j += step;
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
 * Calculates the angle at which we cast a ray at the screen's x coordinate.
 */
float	angle_from_x(int x)
{
	float	normal_x;
	float	plane_size;
	int		plane_dist;

	plane_dist = 3;
	normal_x = ((float)x * 2) / WIDTH - 0.5;
	plane_size = plane_dist * tan(FOV / 2) * 2;
	return (atan2f(normal_x, plane_size));
}
