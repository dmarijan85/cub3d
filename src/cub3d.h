/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:00 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/08 20:21:12 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libs/libft/ft_printf.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define PI 3.14159265358979323846

typedef enum s_bts
{
	NONE = -1,
	EAST,
	NORTH,
	WEST,
	SOUTH,
}				t_bts;

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_fcoord
{
	float			x;
	float			y;
}				t_fcoord;

typedef struct s_square
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				fc[3];
	int				cc[3];
	char			**map;
	char			*gnl;
	int				mapdepth;
	int				infonumber;
	char			player;
	t_fcoord		pcoord; //player coords
	float			centerangle;
	bool			coneflag;
	int				pnbr;
	float			angle;
	float			*cone;
	mlx_t			*window;
	mlx_image_t		*floppatron; //image instance that encompasses the entire fov
	int				bts;
	float			hit_coord; //x and y point where the last ray hit a wall
	int				winheight;
	int				winwidth;
	mlx_texture_t	*ntext;
	mlx_texture_t	*stext;
	mlx_texture_t	*wtext;
	mlx_texture_t	*etext;
	mlx_image_t		*nwall;
	mlx_image_t		*swall;
	mlx_image_t		*wwall;
	mlx_image_t		*ewall;
}				t_square;

void		minecraft(t_square *sq);
int			ft_isspace(char c);
int			flood_fill(t_square *sq, char **map, t_coord player);
int			ft_size(char **map);
void		xrayingit(t_square *sq);
void		die(char *errmsg, t_square *sq, int fd);
void		picture_this(t_square *sq);
void		trump_deluxe(t_square *sq);
void		ft_putplane(int *fcrgb, int *ccrgb, mlx_image_t *image);
float		dtr(float degrees);
void		hook(void *param);
uint32_t	get_colour(int *color);
float		absf(float num);
void		the_brutalist(t_square *sq, int i, mlx_image_t *wall);

#endif
