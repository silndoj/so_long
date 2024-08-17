/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:38:05 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/17 04:51:07 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error("--Allocation Error--", game);
	if (argc != 2)
		ft_error("---The game need's 1 ARG , to START---", game);
	map_pass(game, argv);
	if (its_map(game, argv) == 0)
	{
		txt_upload(game);
		img_pass(game);
		player_pass(game);
	}
	mlx_key_hook(game->mlx_c->mlx, &ft_options, game);
	mlx_loop(game->mlx_c->mlx);
	mlx_terminate(game->mlx_c->mlx);
	free(game);
	return (0);
}
