/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iminyourwalls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:11:02 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/15 15:00:11 by dmarijan         ###   LAUSANNE.ch       */
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
	if (height > 0 && sq->bts[i] == NORTH)
		ft_putcolumn(sq->nwall, wall, height, i);
	else if (height > 0 && sq->bts[i] == SOUTH)
		ft_putcolumn(sq->swall, wall, height, i);
	else if (height > 0 && sq->bts[i] == EAST)
		ft_putcolumn(sq->ewall, wall, height, i);
	else if (height > 0 && sq->bts[i] == WEST)
		ft_putcolumn(sq->wwall, wall, height, i);
	else
		return ;
}

int		highest(int *count)
{
	int	i;
	int	highest;
	int	highesti;

	i = 0;
	highest = count[i];
	highesti = i;
	while (i < 4)
	{
		if (count[i] > highest)
		{
			highest = count[i];
			highesti = i;
		}
		i++;
	}
	free(count);
	return (NORTH);
	if (highesti == 0)
		return (EAST);
	else if (highesti == 1)
		return (NORTH);
	else if (highesti == 2)
		return (WEST);
	else if (highesti == 3)
		return (SOUTH);
}

int		ft_smoothlikebutter(t_square *sq, int liar)
{
	float	liardistance;
	int		i;
	int		*count;

	i = -15;
	count = malloc(4 * sizeof(int));
	count[WEST] = 0;
	count[NORTH] = 0;
	count[SOUTH] = 0;
	count[EAST] = 0;
	liardistance = sq->cone[liar];
	while (i < 15)
	{
		if (liar + i < sq->winwidth && liar + i > 0 && absf(liardistance - sq->cone[liar + i]) < 2 && sq->bts[liar + i] != NONE)
			count[sq->bts[liar + i]]++;
		i++;
	}
	return (highest(count));
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
		sq->bts[sq->liar[i]] = ft_smoothlikebutter(sq, sq->liar[i]);
		i++;
	}
	i = 0;
	while (i < sq->winwidth)
	{
		the_brutalist(sq, i, wall);
		i++;
	}
	mlx_image_to_window(sq->window, wall, 0, 0);
	sq->floppatron = wall;
}
