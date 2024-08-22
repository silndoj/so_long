/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silndoj <silndoj@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:30:10 by silndoj           #+#    #+#             */
/*   Updated: 2024/08/22 06:14:37 by silndoj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../tools/lib/libft/libft.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 	50

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
}						t_game;

//Error_Print
void		ft_error(char *str, t_game *game);

//Map_Check
int			map_pass(t_game *game, char **argv);
int			map_check(t_game *game, char **argv);
int			map_width(char *line);
int			add_line_map(t_game *game, char *line);
int			check_walls(t_game *game);
int			check_square(t_game *game);
int			check_ffill(t_game *game, char **argv);
void		read_all(t_game *game, char *mapline);
void		object_count(t_game *game);
void		ffill(t_game *game, int x, int y);
void		player_pos(t_game *game);

//Customization_MAP
void		txt_upload(t_game *game);
void		img_pass(t_game *game);
void		player_pass(t_game *game);
void		mv_count(t_game *game, int dir, int y, int x);
void		mv_player(t_game *game, int dir);
void		opt_upload(mlx_key_data_t keydata, void *arg);
void		reload_player(t_game *game);
void		check_exit_move(t_game *game, int dir);
void		floor_pass(t_game *game, int x, int y);
//Free_Everything
void		free_txt(t_game *game);
void		free_2d(char **dd);
void		free_all(t_game	*game);

#endif
