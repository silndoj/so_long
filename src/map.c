/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 05:06:33 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/21 21:39:20 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	read_all(t_game *game, char *mapline)
{
	int		i;

	i = 1;
	while (mapline != NULL)
	{
		game->map[i] = ft_strdup(mapline);
		if (!game->map[i])
			ft_error("Memory allocation error", game);
		free(mapline);
		mapline = get_next_line(game->fd);
		i++;
	}
	game->map[i] = NULL;
	game->height = i;
}

int	map_pass(t_game *game, char **argv)
{
	char	*mapline;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
		ft_error("Failed to open map file", game);
	game->map = (char **)malloc(sizeof(char *) * 100);
	if (!game->map)
		ft_error("Memory allocation error", game);
	mapline = get_next_line(game->fd);
	if (!mapline)
		ft_error("Empty map", game);
	game->map[0] = ft_strdup(mapline);
	if (!game->map[0])
		ft_error("Memory allocation error", game);
	free (mapline);
	mapline = get_next_line(game->fd);
	read_all(game, mapline);
	return (1);
}
