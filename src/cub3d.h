/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:00 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/01 19:31:35 by dmarijan         ###   ########.fr       */
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
	int			pnbr;
	int			angle;
	float		*cone;
}				t_square;

void	minecraft(t_square *sq);
int		ft_isspace(char c);
int		flood_fill(t_square *sq, char **map, t_coord player);
int		ft_size(char **map);
void	xrayingit(t_square *sq);

#endif
