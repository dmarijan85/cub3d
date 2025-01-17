/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:00 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/17 14:13:27 by dmarijan         ###   ########.fr       */
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
# include "libs/libft/ft_printf.h"
# include "libs/MLX42/include/MLX42/MLX42.h"
# include "libs/MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_square
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fc[3];
	int		cc[3];
	char	**map;
	int		mapdepth;
	int		infonumber;
}				t_square;

void	minecraft(t_square *sq);
int		ft_isspace(char c);
int		flood_fill(t_square *sq, char **map, t_coord player);

#endif
