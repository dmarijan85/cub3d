/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iminyourwalls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:11:02 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/10 14:00:15 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdint.h>

void	ft_putcolumn(int *rgb, mlx_image_t *image, float wallheight, uint32_t x)
{
	uint32_t	y;

	if (x < image->width)
	{
		y = (image->height - wallheight) / 2;
		if ((int)y < 0)
			y = 0;
		while (wallheight > 0)
		{
			if (wallheight < image->height)
				mlx_put_pixel(image, x, y + wallheight, get_colour(rgb));
			wallheight--;
		}
	}
}

//The Brutalist is a 2024 epic period drama film directed and produced by Brady
//Corbet, who co-wrote the screenplay with Mona Fastvold. 
//It stars Adrien Brody as a Hungarian-born Jewish Holocaust survivor who 
//immigrates to the United States, where he struggles to achieve the American 
//Dream until a wealthy client changes his life.
void	the_brutalist(t_square *sq, int i, mlx_image_t *wall)
{
	float		height;

	if (sq->cone[i] == -1)
		return ;
	height = ((0.75 * sq->winheight) / (sq->cone[i] * tan(dtr(60.0 / 2))));
	if (height > 0)
		ft_putcolumn(sq->tempwall, wall, height, i);
}

//build the wall!!!
void	trump_deluxe(t_square *sq)
{
	int			i;
	mlx_image_t	*wall;

	wall = mlx_new_image(sq->window, sq->winwidth, sq->winheight);
	i = 0;
	while (i < sq->winwidth)
	{
		the_brutalist(sq, i, wall);
		i++;
	}
	mlx_image_to_window(sq->window, wall, 0, 0);
	sq->floppatron = wall;
}
