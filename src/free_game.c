/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 04:43:16 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/21 23:20:43 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_2d(char **dd)
{
	int	i;

	i = 0;
	while (dd[i])
	{
		free(dd[i]);
		i++;
	}
	free(dd);
}

void	free_all(t_game	*game)
{
	if (game)
	{
		if (game->map)
			free_2d(game->map);
		if (game)
			free_txt(game);
		free(game);
	}
}

void	free_txt(t_game *game)
{
	if (game->collect_t)
		mlx_delete_texture(game->collect_t);
	if (game->floor_t)
		mlx_delete_texture(game->floor_t);
	if (game->wall_i)
		mlx_delete_texture(game->wall_t);
	if (game->player_t)
		mlx_delete_texture(game->player_t);
	if (game->exit_t)
		mlx_delete_texture(game->exit_t);
	if (game->exit_i)
		mlx_delete_image(game->mlx, game->exit_i);
	if (game->wall_i)
		mlx_delete_image(game->mlx, game->exit_i);
	if (game->floor_i)
		mlx_delete_image(game->mlx, game->exit_i);
	if (game->collect_i)
		mlx_delete_image(game->mlx, game->exit_i);
	if (game->player_i)
		mlx_delete_image(game->mlx, game->player_i);
}
