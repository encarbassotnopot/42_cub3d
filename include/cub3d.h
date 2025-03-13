/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:26:49 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/03/13 12:26:49 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include "mathematics.h"
# include "structs.h"
# include "parser.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 512
# define HEIGHT 512
# define FOV M_PI_2

void	render_scene(t_game *game);
void	ft_error_msg(char *str, t_game *game);
void	free_strucs(t_game *game);
void	ft_free_map(char **map);
void	debug_info(t_info *info);
void	init_map(char *file, t_game *game);
int32_t	run_mlx(t_game *game);
#endif
