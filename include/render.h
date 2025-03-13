/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:32:18 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/03/13 12:32:18 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

float	angle_from_x(int x);
void	draw_oob(t_game *game, int x);
void	draw_wall(t_game *game, t_vec2 *ray, int x, char face);
#endif
