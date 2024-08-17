/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 04:43:16 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/17 05:02:09 by silndoj          ###   ########.fr       */
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
	if (game->mlx_c->collect_t)
		mlx_delete_texture(game->mlx_c->collect_t);
	if (game->mlx_c->floor_t)
		mlx_delete_texture(game->mlx_c->floor_t);
	if (game->mlx_c->wall_i)
		mlx_delete_texture(game->mlx_c->wall_t);
	if (game->mlx_c->player_t)
		mlx_delete_texture(game->mlx_c->player_t);
	if (game->mlx_c->exit_t)
		mlx_delete_texture(game->mlx_c->exit_t);
	if (game->mlx_c->exit_i)
		mlx_delete_image(game->mlx_c->mlx, game->mlx_c->exit_i);
	if (game->mlx_c->wall_i)
		mlx_delete_image(game->mlx_c->mlx, game->mlx_c->exit_i);
	if (game->mlx_c->floor_i)
		mlx_delete_image(game->mlx_c->mlx, game->mlx_c->exit_i);
	if (game->mlx_c->collect_i)
		mlx_delete_image(game->mlx_c->mlx, game->mlx_c->exit_i);
	if (game->mlx_c->player_i)
		mlx_delete_image(game->mlx_c->mlx, game->mlx_c->player_i);
}
