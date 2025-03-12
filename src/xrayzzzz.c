/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrayzzzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:48:56 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 15:52:54 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdbool.h>

void	ft_gabagool(t_square *sq, float pooop, int walltype)
{
	float	wallsize;

	wallsize = 0;
	if (walltype == WEST)
		wallsize = sq->wwall->width;
	else if (walltype == EAST)
		wallsize = sq->ewall->width;
	else if (walltype == NORTH)
		wallsize = sq->nwall->width;
	else if (walltype == SOUTH)
		wallsize = sq->swall->width;
	sq->bts = walltype;
	sq->hit_coord = (pooop - (int)pooop) * wallsize;
	if (walltype == WEST || walltype == SOUTH)
		sq->hit_coord = wallsize - sq->hit_coord - 1;
}

void	ft_bts(t_square *sq, float x, float y, float i)
{
	if (x == (int)x && y == (int)y)
	{
		if (i == 0)
			sq->bts = NONE;
	}
	else if (x == (int)x)
	{
		if (sq->angle > 90 && sq->angle < 270)
			ft_gabagool(sq, y, WEST);
		else
			ft_gabagool(sq, y, EAST);
	}
	else if (y == (int)y)
	{
		if (sq->angle > 0 && sq->angle < 180)
			ft_gabagool(sq, x, NORTH);
		else
			ft_gabagool(sq, x, SOUTH);
	}
}

float	zeus(t_square *sq, int i, float slope)
{
	float	x;
	float	y;
	bool	flag;

	x = sq->pcoord.x;
	y = sq->pcoord.y;
	while (!gonetoofar(sq->pcoord, x, y))
	{
		flag = false;
		movement(sq, &x, &y, slope);
		if (y == (int)y && sq->angle > 0 && sq->angle < 180)
			if (y - 1 >= 0 && sq->map[(int)y - 1][(int)x] == '1')
				flag = true;
		if (x == (int)x && sq->angle > 90 && sq->angle < 270)
			if (x - 1 >= 0 && sq->map[(int)y][(int)x - 1] == '1')
				flag = true;
		if (sq->map[(int)y][(int)x] == '1' || flag)
		{
			ft_bts(sq, x, y, i);
			return (sqrt(abspwr(absf(x) - sq->pcoord.x) \
				+ abspwr(absf(y) - sq->pcoord.y)));
		}
	}
	return (-1);
}

void	coneheads(t_square *sq, mlx_image_t *wall)
{
	float	i;
	float	angle;
	float	tdist;
	float	slope;

	i = 0;
	while (i < sq->winwidth)
	{
		angle = sq->centerangle + (30.0 - ((60.0 / sq->winwidth) * i));
		if (angle < 0)
			angle = 360 + angle;
		else if (angle >= 360)
			angle -= 360;
		sq->angle = angle;
		if (sq->angle == 90 || sq->angle == 270)
			slope = 0;
		else
			slope = tanf(dtr(sq->angle));
		tdist = zeus(sq, i, slope);
		sq->cone[(int)i] = tdist * cos(dtr(sq->angle - (sq->centerangle)));
		the_brutalist(sq, i, wall);
		i++;
	}
}

void	xrayingit(t_square *sq)
{
	float		*cone;

	if (sq->coneflag == false)
	{
		cone = malloc((sq->winwidth + 1) * sizeof(float));
		if (!cone)
			die("Malloc fail\n", sq, 0);
		cone[sq->winwidth] = -1;
		sq->cone = cone;
		sq->coneflag = true;
	}
	coneheads(sq, sq->floppatron);
}
