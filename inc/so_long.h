/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:30:10 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/17 04:59:27 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../tools/lib/libft/libft.h"
#include "../tools/lib/printf/ft_printf.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*floor_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*player_i;
	mlx_image_t		*exit_i;
	mlx_image_t		*collect_i;
	mlx_texture_t	*floor_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*player_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*collect_t;
}	t_mlx;

typedef struct s_game
{
	int				fd;
	int				height;
	int				width;
	int				p_count;
	int				mv_count;
	int				c_count;
	int				e_count;
	int				e_open;
	int				x_player;
	int				y_player;
	char			**map;
	t_mlx			*mlx_c;
}	t_game;

//Error_Print
void		ft_error(char *str, t_game *game);

//Map_Check
int			map_pass(t_game *game, char **argv);
int			add_line_map(t_game *game, char *line);
int			ft_map_width(char *line);
int			check_walls(t_game *game);
int			check_square(t_game *game);
int			check_floodfill(t_game *game, char **argv);
int			its_map(t_game *game, char **argv);
void		check_count_items(t_game *game);
void		floodfill(t_game *game, int x, int y);
void		find_position_player(t_game *game);

//Customization_MAP
void		txt_upload(t_game *game);
void		img_pass(t_game *game);
void		player_pass(t_game *game);
void		mv_count(t_game *game, int dir, int y, int x);
void		move_player(t_game *game, int dir);
void		opt_upload(mlx_key_data_t keydata, void *arg);
void		reload_player(t_game *game);
void		check_exit_move(t_game *game, int dir);
void		read_while(t_game *game, char *line);

//Free_Everything
void		free_txt(t_game *game);
void		free_2d(char **dd);
void		free_all(t_game	*game);

#endif
