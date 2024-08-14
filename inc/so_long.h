/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:30:10 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/12 02:40:44 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../tools/lib/libft/libft.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# define WIDTH 2000
# define HEIGHT 1500

// typedef struct s_game
//{
//	void			*mlx;
//	void			*window;
//	t_vector		wndw_size;
//	t_tile			**tilemap;
//	t_player		player;
//	int				og_collects;
//	int				collects;
//	int				moves;
//	t_enemy			*enemy_list;
//	t_vector		img_size;
//	t_wall_img		wall_imgs;
//	t_collect_img	collects_imgs;
//	t_enemy_img		enemy_imgs;
//	void			*door_open_img;
//	void			*door_close_img;
//	t_effect		effect;
//	void			*red_panel;
//	void			*white_panel;
// }	t_game;

void ft_error();
void background(mlx_t *mlx);

#endif
