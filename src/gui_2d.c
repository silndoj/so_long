/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:14:24 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/22 06:13:39 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	txt_upload(t_game *game)
{
	game->mlx = mlx_init(game->width * SIZE,
			game->height * SIZE, "so_long", false);
	game->floor_t = mlx_load_png("tools/assets/floor.png");
	game->exit_t = mlx_load_png("tools/assets/exit.png");
	game->player_t = mlx_load_png("tools/assets/player.png");
	game->wall_t = mlx_load_png("tools/assets/wall.png");
	game->collect_t = mlx_load_png("tools/assets/collect.png");
	if (!game->floor_t || !game->exit_t || !game->player_t
		|| !game->wall_t || !game->collect_t)
		return ;
	game->floor_i = mlx_texture_to_image(game->mlx, game->floor_t);
	mlx_resize_image(game->floor_i, SIZE, SIZE);
	game->exit_i = mlx_texture_to_image(game->mlx, game->exit_t);
	mlx_resize_image(game->exit_i, SIZE, SIZE);
	game->player_i = mlx_texture_to_image(game->mlx, game->player_t);
	mlx_resize_image(game->player_i, SIZE, SIZE);
	game->wall_i = mlx_texture_to_image(game->mlx, game->wall_t);
	mlx_resize_image(game->wall_i, SIZE, SIZE);
	game->collect_i = mlx_texture_to_image(game->mlx, game->collect_t);
	mlx_resize_image(game->collect_i, SIZE, SIZE);
	if (!game->floor_i || !game->exit_i
		|| !game->player_i || !game->wall_i || !game->collect_i)
		return ;
}

void	floor_pass(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'C'
		|| game->map[y][x] == 'P')
		mlx_image_to_window(game->mlx,
			game->floor_i, x * SIZE, y * SIZE);
}

void	img_pass(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			floor_pass(game, x, y);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx,
					game->wall_i, x * SIZE, y * SIZE);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->collect_i, x * SIZE,
					y * SIZE);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx,
					game->exit_i, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void	player_pass(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player_i, x * SIZE,
					y * SIZE);
			x++;
		}
		y++;
	}
}
