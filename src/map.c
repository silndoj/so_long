/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 05:06:33 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/17 05:09:24 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_width(char *line)
{
	int	width;

	width = 0;
	while (line[width] != '\0')
		width++;
	if (line[width - 1] == '\n')
		width--;
	return (width);
}

void	read_while(t_game *game, char *line)
{
	int		i;

	i = 1;
	while (line != NULL)
	{
		if (i > 100)
			ft_error("I´m sorry your map is so_long!", game);
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			ft_error("Memory allocation error", game);
		free(line);
		line = get_next_line(game->fd);
		i++;
	}
	game->map[i] = NULL;
	game->map_height = i;
}

int	map_read(t_game *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
		ft_error("Failed to open map file", game);
	game->map = (char **)malloc(sizeof(char *) * 100);
	if (!game->map)
		ft_error("Memory allocation error", game);
	readmap = get_next_line(game->fd);
	if (!readmap)
		ft_error("Empty map", game);
	game->map[0] = ft_strdup(readmap);
	if (!game->map[0])
		ft_error("Memory allocation error", game);
	free (readmap);
	readmap = get_next_line(game->fd);
	read_while(game, readmap);
	return (1);
}

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == PLAYER)
			{
				game->x_player = x;
				game->y_player = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	ft_map_width(game->map[0]);
	while (x < game->map_width)
	{
		if (game->map[0][x] != WALL
			|| game->map[game->map_height - 1][x] != WALL)
			return (0);
		x++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != WALL
			|| game->map[y][game->map_width - 1] != WALL)
			return (0);
		y++;
	}
	return (1);
}
