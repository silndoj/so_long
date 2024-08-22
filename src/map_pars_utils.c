/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:43:23 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/22 04:30:37 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_width(char *line)
{
	int	width;

	width = 0;
	while (line[width] != '\0')
		width++;
	if (line[width - 1] == '\n')
		width--;
	return (width);
}

void	player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
			{
				game->x_player = x;
				game->y_player = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	map_width(game->map[0]);
	while (x < game->width)
	{
		if (game->map[0][x] != '1'
			|| game->map[game->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1'
			|| game->map[y][game->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
