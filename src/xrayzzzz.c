/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrayzzzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:48:56 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/12 16:25:28 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

float	absf(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	gonetoofar(t_fcoord player, float x, float y)
{
	if ((absf(player.x - x) >= 20) || (absf(player.y - y) >= 20))
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

	radians = degrees * (PI / 180.0);
	return (radians);
}

void	pos_pepe_x(float angle, float *x, float *y)
{
	float	slope;
	float	step;

	slope = tanf(dtr(angle));
	step = 0.42;
	if (angle < 90 || angle > 270)
		*x += step;
	else if (angle > 90 && angle < 270)
		*x -= step;
	if (angle > 0 && angle < 180)
		*y -= absf(slope * step);
	else if (angle > 180 && angle < 360)
		*y += absf(slope * step);
}

void	pos_pepe_y(float angle, float *x, float *y)
{
	float	slope;
	float	step;

	if (angle == 90 || angle == 270)
		slope = 0;
	else
		slope = 1 / tanf(dtr(angle));
	step = 0.42;
	if (angle > 0 && angle < 180)
		*y -= step;
	else if (angle > 180 && angle < 360)
		*y += step;
	if (angle < 90 || angle > 270)
		*x += absf(slope * step);
	else if (angle > 90 && angle < 270)
		*x -= absf(slope * step);
}

void	neg_pepe_x(float angle, float *x, float *y)
{
	float	slope;
	float	step;

	slope = tanf(dtr(angle));
	step = 0.42;
	if (angle < 90 || angle > 270)
		*x -= step;
	else if (angle > 90 && angle < 270)
		*x += step;
	if (angle > 0 && angle < 180)
		*y += absf(slope * step);
	else if (angle > 180 && angle < 360)
		*y -= absf(slope * step);
}

void	neg_pepe_y(float angle, float *x, float *y)
{
	float	slope;
	float	step;

	if (angle == 90 || angle == 270)
		slope = 0;
	else
		slope = 1 / tanf(dtr(angle));
	step = 0.42;
	if (angle > 0 && angle < 180)
		*y += step;
	else if (angle > 180 && angle < 360)
		*y -= step;
	if (angle < 90 || angle > 270)
		*x -= absf(slope * step);
	else if (angle > 90 && angle < 270)
		*x += absf(slope * step);
}

bool	checkpepe(t_square *sq, float px, float py)
{
	float	pepeangle;
	float	pepeslope;
	float	nx;
	float	ny;

	nx = px;
	ny = py;
	pepeangle = sq->angle + 90;
	if (pepeangle >= 360)
		pepeangle -= 360;
	if (pepeangle == 0 || pepeangle == 90 || pepeangle == 180 || pepeangle == 270)
		pepeslope = 0;
	else
		pepeslope = (tanf(dtr(pepeangle)));
	if (absf(pepeslope) > 1 || pepeangle == 90 || pepeangle == 270)
		pos_pepe_y(pepeangle, &px, &py);
	else
		pos_pepe_x(pepeangle, &px, &py);
	if (absf(pepeslope) > 1 || pepeangle == 90 || pepeangle == 270)
		neg_pepe_y(pepeangle, &nx, &ny);
	else
		neg_pepe_x(pepeangle, &nx, &ny);
	if (sq->map[(int)py][(int)px] == '1' && sq->map[(int)ny][(int)nx] == '1')
		return (true);
	return (false);
}

float	big_floppa_returns(t_square *sq, float x, float y, float step)
{
	float	slope;
	float	xog;
	float	yog;

	xog = x;
	yog = y;
	if ((sq->angle == 90) || (sq->angle == 270))
		slope = 0;
	else
		slope = 1 / tanf(dtr(sq->angle));
	if (sq->angle > 0 && sq->angle < 180)
		y -= step;
	else if (sq->angle > 180 && sq->angle < 360)
		y += step;
	if (sq->angle < 90 || sq->angle > 270)
		x += absf(slope * step);
	else if (sq->angle > 90 && sq->angle < 270)
		x -= absf(slope * step);
	if (((int)x != (int)xog || (int)y != (int)yog) || ((sq->map[(int)y][(int)x] == '1')))
		return (big_floppa_returns(sq, xog, yog, step / 2));
	if (step > 0.01)
		return (step);
	return (0.01);
}

float	big_floppa(t_square *sq, float x, float y, float step)
{
	float	slope;
	float	xog;
	float	yog;

	xog = x;
	yog = y;
	if (sq->angle == 90 || sq->angle == 270)
		slope = 0;
	else
		slope = tanf(dtr(sq->angle));
	if (sq->angle < 90 || sq->angle > 270)
		x += step;
	else if (sq->angle > 90 && sq->angle < 270)
		x -= step;
	if (sq->angle > 0 && sq->angle < 180)
		y -= absf(slope * step);
	else if (sq->angle > 180 && sq->angle < 360)
		y += absf(slope * step);
	if (((int)x != (int)xog || (int)y != (int)yog) || ((sq->map[(int)y][(int)x] == '1')))
		return (big_floppa(sq, xog, yog, step / 2));
	if (step > 0.01)
		return (step);
	return (0.01);
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

void	move_x(t_square *sq, float step, float *x, float *y)
{
	float	slope;

	slope = tanf(dtr(sq->angle));
	step = big_floppa(sq, *x, *y, step);
	if (sq->angle < 90 || sq->angle > 270)
		*x += step;
	else if (sq->angle > 90 && sq->angle < 270)
		*x -= step;
	if (sq->angle > 0 && sq->angle < 180)
		*y -= absf(slope * step);
	else if (sq->angle > 180 && sq->angle < 360)
		*y += absf(slope * step);
}

void	move_y(t_square *sq, float step, float *x, float *y)
{
	float	slope;

	if (sq->angle == 90 || sq->angle == 270)
		slope = 0;
	else
		slope = 1 / tanf(dtr(sq->angle));
	step = big_floppa_returns(sq, *x, *y, step);
	if (sq->angle > 0 && sq->angle < 180)
		*y -= step;
	else if (sq->angle > 180 && sq->angle < 360)
		*y += step;
	if (sq->angle < 90 || sq->angle > 270)
		*x += absf(slope * step);
	else if (sq->angle > 90 && sq->angle < 270)
		*x -= absf(slope * step);
}

float	ft_roundingit(t_square *sq, float *x, float *y)
{
	float	whole;
	float	cx;
	float	cy;

	cx = *x;
	cy = *y;
	if (checkpepe(sq, *x, *y))
	{
		whole = (int)cx;
		cx -= whole;
		cx *= 1000;
		whole = (int)cy;
		cy -= whole;
		cy *= 1000;
		if ((cy >= 975 && cx >= 975) || (cy <= 25 && cx <= 25) || (cy >= 975 && cx <= 25) || (cy <= 25 && cx >= 975))
			return (sqrt(abspwr(absf(roundf(*x)) - sq->pcoord.x) + abspwr(absf(roundf(*y)) - sq->pcoord.y)));
	}
	if (sq->map[(int)*y][(int)*x] == '1')
		return (sqrt(abspwr(absf(*x) - sq->pcoord.x) + abspwr(absf(*y) - sq->pcoord.y)));
	return (0);
}

float	zeus(t_square *sq)
{
	float	slope;
	float	x;
	float	y;
	float	distance;

	x = sq->pcoord.x;
	y = sq->pcoord.y;
	if (sq->angle == 90 || sq->angle == 270)
		slope = 0;
	else
		slope = tanf(dtr(sq->angle));
	while (!gonetoofar(sq->pcoord, x, y))
	{
		if (absf(slope) > 1 || sq->angle == 90 || sq->angle == 270)
			move_y(sq, 0.1, &x, &y);
		else
			move_x(sq, 0.1, &x, &y);
		distance = ft_roundingit(sq, &x, &y);
		if (distance)
			return (distance);
	}
	return (-1);
}

void	coneheads(t_square *sq)
{
	float	*cone;
	float	i;
	float	angle;

	cone = malloc((sq->winwidth + 1) * sizeof(float));
	cone[sq->winwidth] = -1;
	i = 0;
	while (i < sq->winwidth)
	{
		angle = sq->centerangle + (30.0 - ((60.0 / sq->winwidth) * i));
		if (angle < 0)
			angle = 360 + angle;
		else if (angle >= 360)
			angle -= 360;
		sq->angle = angle;
		cone[(int)i] = zeus(sq);
		i++;
	}
	sq->cone = cone;
}

void	xrayingit(t_square *sq)
{
	coneheads(sq);
}
