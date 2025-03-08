/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrayzzzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:48:56 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/08 20:43:14 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdbool.h>

float	absf(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	gonetoofar(t_fcoord player, float x, float y)
{
	if ((absf(player.x - x) >= 100) || (absf(player.y - y) >= 100))
		return (1);
	return (0);
}

float	abspwr(float num)
{
	num = absf(num);
	num = num * num;
	return (num);
}

float	dtr(float degrees)
{
	float	radians;

	if (degrees >= 360)
		degrees -= 360;
	if (degrees < 0)
		degrees += 360;
	radians = degrees * (PI / 180.0);
	return (radians);
}

float	ft_round(float nbr)
{
	float	whole;

	whole = (int)nbr;
	nbr -= whole;
	nbr *= 10;
	if (nbr <= 1)
		return (whole);
	else if (nbr >= 9)
		return (whole + 1.0);
	return (whole + (nbr / 10));
}

/*
void	set_hit(t_square *sq, float x, float y)
{
	if (x != (int)x)
	{
		if (sq->bts == WEST);
		sq->hit_coord = (x - (int)x) *  ;
	}
		else if (y != (int)y)
		sq->hit_coord = y;
}*/

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
			sq->bts = WEST;
		else
			sq->bts = EAST;
		sq->hit_coord = (y - (int)y) * 500;
	}
	else if (y == (int)y)
	{
		if (sq->angle > 0 && sq->angle < 180)
			sq->bts = NORTH;
		else
			sq->bts = SOUTH;
		sq->hit_coord = (x - (int)x) * 500;
	}
	if (sq->bts == WEST || sq->bts == SOUTH)
		sq->hit_coord = 500 - sq->hit_coord - 1;
}

float	safe_rounder(float number, bool ceil)
{
	if (ceil && (number != (int)number))
		number = ceilf(number);
	else if (!ceil && (number != (int)number))
		number = floorf(number);
	else if (ceil && number == (int)number)
		number = ceilf(number + 0.001);
	else if (!ceil && number == (int)number)
		number = floorf(number - 0.001);
	return (number);
}

void	fix_x(t_square *sq, float *x, float *y, float slope)
{
	float	tx;

	tx = *x;
	if (sq->angle <= 90 || sq->angle >= 270)
		tx = safe_rounder(*x, true);
	else
		tx = safe_rounder(*x, false);
	if (sq->angle >= 0 && sq->angle <= 180)
		*y -= absf((tx - *x) * slope);
	else
		*y += absf((tx - *x) * slope);
	*x = tx;
}

void	fix_y(t_square *sq, float *x, float *y, float slope)
{
	float	ty;

	ty = *y;
	if (sq->angle >= 0 && sq->angle <= 180)
		ty = safe_rounder(*y, false);
	else
		ty = safe_rounder(*y, true);
	if (sq->angle <= 90 || sq->angle >= 270)
		*x += absf((ty - *y) / slope);
	else
		*x -= absf((ty - *y) / slope);
	*y = ty;
}

void	safe_fix_x(t_square *sq, float *x, float *y, float slope)
{
	float	tx;

	tx = *x;
	if (sq->angle <= 90 || sq->angle >= 270)
		tx = (ceilf(*x));
	else
		tx = (floorf(*x));
	if (sq->angle >= 0 && sq->angle <= 180)
		*y -= absf((tx - *x) * slope);
	else
		*y += absf((tx - *x) * slope);
	*x = tx;
}

void	safe_fix_y(t_square *sq, float *x, float *y, float slope)
{
	float	ty;

	ty = *y;
	if (sq->angle >= 0 && sq->angle <= 180)
		ty = floorf(*y);
	else
		ty = ceilf(*y);
	if (sq->angle <= 90 || sq->angle >= 270)
		*x += absf((ty - *y) / slope);
	else
		*x -= absf((ty - *y) / slope);
	*y = ty;
}

void	handle_pope(t_square *sq, float *x, float *y)
{
	if (sq->angle == 0)
		*x = (ceilf(*x + 0.0001));
	else if (sq->angle == 180)
		*x = (floorf(*x - 0.0001));
	if (sq->angle == 270)
		*y = (ceilf(*y + 0.0001));
	else if (sq->angle == 90)
		*y = (floorf(*y - 0.0001));
}

void	fix_both(t_square *sq, float *x, float *y)
{
	if (sq->angle > 270 && sq->angle < 90)
		*x = ceilf(*x + 0.001f);
	else
		*x = floorf(*x - 0.001f);
	if (sq->angle > 0 && sq->angle < 180)
		*y = floorf(*y - 0.001f);
	else
		*y = ceilf(*y + 0.001f);
}

void	movement(t_square *sq, float *x, float *y, float slope)
{
	float	rdx;
	float	rdy;

	if (slope == 0)
		handle_pope(sq, x, y);
	else
	{
		if (sq->angle <= 90 || sq->angle >= 270)
			rdx = absf((safe_rounder(*x, true) - *x));
		else
			rdx = absf((*x - safe_rounder(*x, false)));
		if (sq->angle >= 0 && sq->angle <= 180)
			rdy = absf((*y - safe_rounder(*y, false)) / slope);
		else
			rdy = absf((safe_rounder(*y, true) - *y) / slope);
		if (rdx < rdy)
			fix_x(sq, x, y, slope);
		else
			fix_y(sq, x, y, slope);
	}
}

float	zeus(t_square *sq, int i)
{
	float	slope;
	float	x;
	float	y;
	bool	flag;

	x = sq->pcoord.x;
	y = sq->pcoord.y;
	if (sq->angle == 90 || sq->angle == 270)
		slope = 0;
	else
		slope = tanf(dtr(sq->angle));
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
			return (sqrt(abspwr(absf(x) - sq->pcoord.x) + abspwr(absf(y) - sq->pcoord.y)));
		}
	}
	return (-1);
}

void	coneheads(t_square *sq, mlx_image_t *wall)
{
	float	i;
	float	angle;
	float	tdist;

	i = 0;
	while (i < sq->winwidth)
	{
		angle = sq->centerangle + (30.0 - ((60.0 / sq->winwidth) * i));
		if (angle < 0)
			angle = 360 + angle;
		else if (angle >= 360)
			angle -= 360;
		sq->angle = angle;
		tdist = zeus(sq, i);
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
