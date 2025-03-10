#include "cub3d.h"
#include "render.h"

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
	height = 1 / dist * HEIGHT / cosf(angle_from_x(x));
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
 * Calculates the angle at which we cast a ray at the screen's x coordinate.
 */
float	angle_from_x(int x)
{
	float normal_x;
	float plane_size;
	int plane_dist;

	plane_dist = 3;
	normal_x = ((float)x * 2) / WIDTH - 0.5;
	plane_size = plane_dist * tan(FOV / 2) * 2;
	return (atan2f(normal_x, plane_size));
}