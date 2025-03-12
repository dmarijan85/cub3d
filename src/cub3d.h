/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:00 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 16:23:22 by dmarijan         ###   LAUSANNE.ch       */
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
	//parsing variables
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
	t_fcoord		pcoord;

	//vision variables
	float			centerangle;
	bool			coneflag;
	int				pnbr;
	float			angle;
	float			*cone;
	//entire fov walls
	mlx_image_t		*floppatron;

	//last wall found's orientation and hit coordinates
	int				bts;
	float			hit_coord;

	//window related stuff
	mlx_t			*window;
	int				winheight;
	int				winwidth;

	//texture variables for each kind of wall
	mlx_texture_t	*ntext;
	mlx_texture_t	*stext;
	mlx_texture_t	*wtext;
	mlx_texture_t	*etext;

	//image variables for each kind of wall
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
int			isokay(t_square *sq, char c, t_coord player);
int			gonetoofar(t_fcoord player, float x, float y);
void		movement(t_square *sq, float *x, float *y, float slope);
float		abspwr(float num);
void		jarvis_x(float angle, float *x, float *y);
void		jarvis_y(float angle, float *x, float *y);
float		safe_rounder(float number, bool ceil);
void		handle_pope(t_square *sq, float *x, float *y);
void		compute_map(char *str, t_square *sq, int fd);
void		legalize_walls(t_square *sq);
int			isemptyline(char *str);
void		mapdeluxe(t_square *sq);
void		check_replace(char *line, int longest, t_square *sq, int pos);
void		waterbucket(t_square *sq, int x, int y);
void		array_free(char **str);

#endif
