/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:41:51 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/25 17:22:23 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "libs/libft/ft_printf.h"
# include "libs/MLX42/include/MLX42/MLX42.h"
# include "libs/MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_flood
{
	int				exit;
	int				collect;
}				t_flood;

typedef struct s_game
{
	int				**map;
	int				height;
	int				width;
	t_coord			player;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
	t_coord			exit;
	t_coord			*coll;
	int				count_coll;
	int				count_exit;
	int				count_player;
}				t_game;

typedef struct s_root
{
	void			*mlx;
	mlx_image_t		*mlx_img;
	t_game			*game;
	mlx_image_t		*player;
	mlx_image_t		*exit;
	mlx_image_t		*coll;
	mlx_image_t		*wall;
	mlx_image_t		*ground;
}				t_root;

void	die(char *errmsg, int errnum);
void	draw(t_root *root);
void	key_press(mlx_key_data_t keydata, void *param);
void	close_window(void *param);
void	game_destroy(t_game *game);
void	game_init(t_root *root, char *filename);
void	map_height(t_root *root, char *file);
void	map_init(t_root *root, char *filename);
void	map_isvalid(t_root *root, char *file);
void	map_parsing(t_root *root, char *file);
void	map_read(t_root *root, char *file);
void	map_width(t_root *root, char *file);
void	move_up(t_root *root, int x, int y);
void	move_down(t_root *root, int x, int y);
void	move_left(t_root *root, int x, int y);
void	move_right(t_root *root, int x, int y);
void	root_destroy(t_root *root, char *errmsg, int errnum);
t_root	*root_init(char *filename);
void	update(t_root *root);
void	texture_load(mlx_t *mlx, mlx_image_t **img, char *path);
int		flood_fill(t_root *root, int **map, t_coord playa, t_flood *floodutils);

#endif
