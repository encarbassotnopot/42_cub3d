#ifndef RENDER_H
# define RENDER_H

float angle_from_x(int x);
void draw_oob(t_game *game, int x);
void draw_wall(t_game *game, float dist, int x, char face);
#endif