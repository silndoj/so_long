/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:34:55 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/12 00:19:04 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	background(mlx_t* mlx)
{
	mlx_texture_t* txt = mlx_load_png("./src/assets/b.png");
	mlx_image_t* img = mlx_texture_to_image(mlx, txt);
	mlx_resize_image(img, 2000, 1500);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(txt);
}
