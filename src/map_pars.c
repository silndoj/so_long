/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:56:49 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/22 04:25:29 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	object_count(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < (game->width))
		{
			if (game->map[y][x] == 'C')
				game->c_count++;
			if (game->map[y][x] == 'P')
				game->p_count++;
			if (game->map[y][x] == 'E')
				game->e_count++;
			if (game->map[y][x] != '1' && game->map[y][x] != '0' &&
					game->map[y][x] != 'C' && game->map[y][x] != 'P' &&
					game->map[y][x] != 'E')
				ft_error("Invalid MAP output.", game);
			x++;
		}
		y++;
	}
}

int	check_square(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
			x++;
		if (x != game->width)
			ft_error("The map isn't squared.", game);
		y++;
	}
	return (1);
}

void	ffill(t_game *map_dup, int x, int y)
{
	if (x < 0 || y < 0 || y >= map_dup->height || x >= map_dup->width)
		return ;
	if (map_dup->map[y][x] == '1')
		return ;
	if (map_dup->map[y][x] == 'C')
		map_dup->c_count++;
	if (map_dup->map[y][x] == 'E')
		map_dup->e_count++;
	map_dup->map[y][x] = '1';
	ffill(map_dup, x, y - 1);
	ffill(map_dup, x, y + 1);
	ffill(map_dup, x - 1, y);
	ffill(map_dup, x + 1, y);
}

int	check_ffill(t_game *game, char **argv)
{
	t_game	*map;

	map = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error("--ALLLOCATION ISSUE--", game);
	map_pass(map, argv);
	object_count(map);
	map->width = map_width(map->map[0]);
	ffill(map, game->x_player, game->y_player);
	if (map->c_count == game->c_count && map->e_count == 1)
	{
		free_all(map);
		return (1);
	}
	free_all(map);
	return (0);
}

int	map_check(t_game *game, char **argv)
{
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		ft_error("--PLEASE INCLUDE A (.ber) MAP--", game);
	game->width = map_width(game->map[0]);
	if (!check_walls(game) || !check_square(game))
		ft_error("--[MAP ISSUE]--", game);
	object_count(game);
	player_pos(game);
	if ((game->p_count != 1) || (game->c_count < 1)
		|| (game->e_count != 1) || (!check_ffill(game, argv)))
		ft_error("--[MAP ISSUE]--", game);
	return (0);
}
