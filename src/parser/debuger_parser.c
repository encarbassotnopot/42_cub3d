/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuger_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:32:05 by ecoma-ba          #+#    #+#             */
/*   Updated: 2025/03/13 12:32:05 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	debug_map(char **mapa)
{
	int	i;

	i = 0;
	if (!mapa)
	{
		printf("no existeix mapa.\n");
		return ;
	}
	printf("Mapa:\n");
	while (mapa[i])
	{
		printf("%s\n", mapa[i]);
		i++;
	}
}

void	debug_info(t_info *info)
{
	printf("Información de texturas y colores:\n");
	printf("NO: %s\n", info->no);
	printf("SO: %s\n", info->so);
	printf("WE: %s\n", info->we);
	printf("EA: %s\n", info->ea);
	printf("C: %04x\n", info->ceiling);
	printf("F: %04x\n", info->floor);
}
