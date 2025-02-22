/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:00 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/22 15:30:58 by dmarijan         ###   LAUSANNE.ch       */
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
	char		*no;
	int			iliar;
	char		*so;
	char		*we;
	char		*ea;
	int			fc[3];
	int			cc[3];
	char		**map;
	char		*gnl;
	int			mapdepth;
	int			infonumber;
	char		player;
	t_fcoord	pcoord;
	float		centerangle;
	bool		coneflag;
	int			pnbr;
	float		angle;
	float		*cone;
	int			*bts;
	int			*liar;
	bool		liarflag;
	mlx_t		*window;
	mlx_image_t	*floppatron;
	int			winheight;
	int			winwidth;
	int			nwall[3];
	int			swall[3];
	int			wwall[3];
	int			ewall[3];
}				t_square;

void		minecraft(t_square *sq);
int			ft_isspace(char c);
int			flood_fill(t_square *sq, char **map, t_coord player);
int			ft_size(char **map);
void		xrayingit(t_square *sq);
void		die(char *errmsg, t_square *sq, int fd);
void		picture_this(t_square *sq);
void		trump_deluxe(t_square *sq);
void		ft_putplane(int *rgb, mlx_image_t *image);
float		dtr(float degrees);
void		hook(void *param);
uint32_t	get_colour(int *color);
float		absf(float num);

#endif
