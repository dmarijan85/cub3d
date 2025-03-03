/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iminyourwalls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:11:02 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/03 18:44:07 by dmarijan         ###   LAUSANNE.ch       */
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
	height = ((sq->winheight) / (sq->cone[i]));
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

bool	diffsign(float	one, float two)
{
	if ((one > 0 && two < 0) || (one < 0 && two > 0))
		return (true);
	return (false);
}

float	slopers(t_square *sq, int i)
{
	float	height;
	float	theight;
	float	slope;

	height = ((0.75 * sq->winheight) / (sq->cone[i] * tan(dtr(60.0 / 2))));
	theight = ((0.75 * sq->winheight) / (sq->cone[i+1] * tan(dtr(60.0 / 2))));
	slope = 1 / (theight - height);
	return (slope);
}

void	flag_liars(t_square *sq, int i)
{
	int		*liar;
	int		j;
	
	j = 0;
	if ((sq->cone[i + 1] == -1) || sq->cone[i - 1] == -1 || diffsign(slopers(sq, i), slopers(sq, i - 1)))
	{
		liar = malloc((sq->iliar + 2) * sizeof(int));
		while (j < sq->iliar && sq->liarflag)
		{
			liar[j] = sq->liar[j];
			j++;
		}
		liar[j] = i;
		liar[j + 1] = -1;
		if (sq->liarflag)
		{
			free(sq->liar);
			sq->liarflag = false;
		}
		sq->liar = liar;
		sq->iliar++;
		sq->liarflag = true;
//		printf("outliar number %i is: %i\n slopeleft: %f\n sloperght %f\n\n", sq->iliar-1, i, slopers(sq, i-1), slopers(sq, i));
	}
}

int		group_avg(t_square *sq, int *i)
{
	float	average;
	int		j;

	j = 1;
	average = sq->liar[*i];
	while (sq->liar[(*i) + 1] != -1 && sq->liar[(*i) + 1] - sq->liar[*i] <= 20)
	{
		j++;
		average += sq->liar[(*i) + 1];
		*i += 1;
	}
	return (roundf(average / j));
}

void	group_liars(t_square *sq)
{
	int	*newliars;
	int	i;
	int	newsize;
	int	j;

	i = 0;
	newsize = 0;
	while (sq->liar[i + 1] != -1 && sq->liar[i + 1] - sq->liar[i] <= 20)
	{
		i++;
		newsize++;
	}
	i = 0;
	newliars = malloc((newsize + 1) * sizeof(int));
	j = 0;
	while (sq->liar[i] != -1 && j < newsize)
	{
		newliars[j] = group_avg(sq, &i);
		j++;
		i++;
	}
	newliars[newsize] = -1;
	free(sq->liar);
	sq->liar = newliars;
}

void	paintoncoords(t_square *sq, int start, int finish, int colour)
{
	int	i;

	i = start;
	while (i <= finish)
		sq->bts[i++] = colour;
}

//we take the center point of the group to decide the colour of the wall
void	artisticshotgunning(t_square *sq)
{
	int	i;

	i = 0;
	while (sq->liar[i] != -1)
	{
		if (i == 0)
			paintoncoords(sq, 0, sq->liar[i], sq->bts[sq->liar[i] / 2]);
		else
			paintoncoords(sq, sq->liar[i - 1], sq->liar[i], sq->bts[(sq->liar[i] + sq->liar[i - 1]) / 2]);
		i++;
	}
}

//build the wall!!!
void	trump_deluxe(t_square *sq)
{
	int			i;
	mlx_image_t	*wall;

	wall = mlx_new_image(sq->window, sq->winwidth, sq->winheight);
	i = 1;
	sq->iliar = 0;
	while (i + 1 < sq->winwidth)
	{
		if (sq->cone[i] != -1)
			flag_liars(sq, i);
		i++;
	}
	i = 0;
//	group_liars(sq);
//	i = 0;
//	while (sq->liar[i] != -1)
//	{
//		printf("newliar in %i is %i\n\n", i, sq->liar[i]);
//		i++;
//	}
//	i = 0;
//	artisticshotgunning(sq);
	while (i < sq->winwidth)
	{
		the_brutalist(sq, i, wall);
		i++;
	}
	mlx_image_to_window(sq->window, wall, 0, 0);
	sq->floppatron = wall;
}
