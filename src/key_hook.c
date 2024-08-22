/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:25:29 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/21 23:32:24 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	opt_upload(mlx_key_data_t keydata, void *game)
{
	t_game	*temp;

	temp = game;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		mv_count(temp, 1, temp->y_player - 1, temp->x_player);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		mv_count(temp, 2, temp->y_player + 1, temp->x_player);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		mv_count(temp, 4, temp->y_player, temp->x_player + 1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		mv_count(temp, 3, temp->y_player, temp->x_player - 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_all(temp);
		exit (0);
	}
}

void	mv_count(t_game *game, int dir, int y, int x)
{
	if (y < game->height && x < game->width && y >= 0 && x >= 0)
	{
		if (game->map[y][x] != '1')
		{
			if (game->map[y][x] == 'C')
			{
				game->map[y][x] = '0';
				game->c_count--;
				if (mlx_image_to_window(game->mlx,
						game->floor_i, x * SIZE, y * SIZE) < 0)
					ft_error("Error rendering floor.", game);
				if (game->c_count == 0)
					game->e_open = 1;
				reload_player(game);
				mv_player(game, dir);
			}
			else if (game->map[y][x] == 'E')
				check_exit_move(game, dir);
			else
				mv_player(game, dir);
		}
	}
}

void	check_exit_move(t_game *game, int dir)
{
	if (game->c_count == 0)
	{
		mv_player(game, dir);
		ft_error("You win. All collectible reached!!", game);
		free_all(game);
	}
}

void	mv_player(t_game *game, int dir)
{
	game->map[game->y_player][game->x_player] = '0';
	if (dir == 1)
	{
		game->y_player--;
		(game->player_i)->instances[0].y -= SIZE;
	}
	if (dir == 4)
	{
		game->x_player++;
		(game->player_i)->instances[0].x += SIZE;
	}
	if (dir == 2)
	{
		game->y_player++;
		(game->player_i)->instances[0].y += SIZE;
	}
	if (dir == 3)
	{
		game->x_player--;
		(game->player_i)->instances[0].x -= SIZE;
	}
	game->map[game->y_player][game->x_player] = 'P';
	game->mv_count++;
	printf("Moves %d\n", game->mv_count);
}

void	reload_player(t_game *game)
{
	mlx_delete_texture(game->player_t);
	mlx_delete_image(game->mlx, game->player_i);
	game->player_t = mlx_load_png("tools/assets/player.png");
	game->player_i = mlx_texture_to_image(game->mlx, game->player_t);
	mlx_resize_image(game->player_i, SIZE, SIZE);
	if (!game->player_i)
		return ;
	mlx_image_to_window(game->mlx, game->player_i,
		game->x_player * SIZE, game->y_player * SIZE);
}
