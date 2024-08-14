/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:38:05 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/11 23:56:55 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	background(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
