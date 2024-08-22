/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:38:05 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/22 03:50:34 by silndoj          ###   ########.fr       */
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
	if (map_check(game, argv) == 0)
	{
		txt_upload(game);
		img_pass(game);
		player_pass(game);
	}
	mlx_key_hook(game->mlx, &opt_upload, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (0);
}
