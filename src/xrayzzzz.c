/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrayzzzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:48:56 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/22 19:29:28 by dmarijan         ###   LAUSANNE.ch       */
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

	if (degrees >= 360)
		degrees -= 360;
	if (degrees < 0)
		degrees += 360;
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

void	comp_upwards(t_square *sq, float *ogx, float *ogy, float step)
{
	float	slope;
	float	tempy;
	float	tempx;

	slope = tanf(dtr(sq->angle));
	tempy = (*ogy) - absf(slope * step);
	tempx = *ogx;
	if (truncf(tempy) != truncf(*ogy))
	{
		if (sq->angle <= 90 || sq->angle >= 270)
			tempx -= (*ogy - truncf(*ogy)) / absf(slope);
		else
			tempx += (*ogy - truncf(*ogy)) / absf(slope);
		*ogy = truncf(*ogy);
		*ogx = tempx;
	}
	else
		*ogy = tempy;
	printf("ogx: %f ogy: %f newy: %f slope: %f, step: %f\n", *ogx, *ogy, tempy, slope, step);
}

void	comp_downwards(t_square *sq, float *ogx, float *ogy, float step)
{
	float	slope;
	float	tempy;
	float	tempx;

	slope = tanf(dtr(sq->angle));
	tempy = (*ogy) + absf(slope * step);
	tempx = *ogx;
	if (truncf(tempy) != truncf(*ogy))
	{
		if (sq->angle <= 90 || sq->angle >= 270)
			tempx -= (truncf(tempy) - *ogy) / absf(slope);
		else
			tempx += (truncf(tempy) - *ogy) / absf(slope);
		*ogy = truncf(tempy);
		*ogx = tempx;
	}
	else
		*ogy = tempy;
//	printf("ogx: %f ogy: %f newx: %f newy: %f slope: %f, step: %f\n", *ogx, *ogy, tempx, tempy, slope, step);
}

void	neo_move_x(t_square *sq, float *ogx, float *ogy)
{
	float	step;

	if (sq->angle <= 90 || sq->angle >= 270)
		step = truncf((*ogx) + 1) - (*ogx);
	else
		step = (*ogx - truncf(*ogx + 1));
	printf("im neo moving X: step: %f, ogx: %f, ogy %f\n", step, *ogx, *ogy);
	*ogx += step;
	if (sq->angle >= 0 && sq->angle <= 180)
		comp_upwards(sq, ogx, ogy, step);
	else if (sq->angle > 180 && sq->angle < 360)
		comp_downwards(sq, ogx, ogy, step);
	printf("im neo moving X AFTER MOVE: step: %f, ogx: %f, ogy %f\n\n", step, *ogx, *ogy);
}

void	comp_right(t_square *sq, float *ogx, float *ogy, float step)
{
	float	slope;
	float	tempy;
	float	tempx;

	if (sq->angle == 90 || sq->angle == 270)
		slope = 0;
	else
		slope = 1 / tanf(dtr(sq->angle));
	tempx = (*ogx) + absf(slope * step);
	tempy = *ogy;
	if (truncf(tempx) != truncf(*ogx))
	{
		if (sq->angle >= 180 && sq->angle <= 0)
			tempy += (truncf(tempx) - *ogx) / absf(slope);
		else
			tempy -= (truncf(tempx) - *ogx) / absf(slope);
		*ogy = tempy;
		*ogx = truncf(tempx);
	}
	else
		*ogy = tempy;
	printf("ogx: %f ogy: %f newx: %f newy: %f slope: %f, step: %f\n", *ogx, *ogy, tempx, tempy, slope, step);
}

void	comp_left(t_square *sq, float *ogx, float *ogy, float step)
{
	float	slope;
	float	tempy;
	float	tempx;

	if (sq->angle == 90 || sq->angle == 270)
		slope = 0;
	else
		slope = 1 / tanf(dtr(sq->angle));
	tempx = (*ogx) - absf(slope * step);
	tempy = *ogy;
	if (truncf(tempx) != truncf(*ogx))
	{
		if (sq->angle >= 180 && sq->angle <= 0)
			tempy += (truncf(tempx) - *ogx) / absf(slope);
		else
			tempy -= (truncf(tempx) - *ogx) / absf(slope);
		*ogy = tempy;
		*ogx = truncf(*ogx);
	}
	else
		*ogy = tempy;
	printf("ogx: %f ogy: %f newx: %f newy: %f slope: %f, step: %f\n", *ogx, *ogy, tempx, tempy, slope, step);
}

void	neo_move_y(t_square *sq, float *ogx, float *ogy)
{
	float	step;

	printf("im neo moving Y\n");
	if ((sq->angle >= 0 && sq->angle <= 180))
		step = (*ogy - truncf(*ogy) + 1);
	else
		step = (truncf(*ogy + 1) - *ogy);
	*ogy += step;
	if (sq->angle < 90 || sq->angle > 270)
		comp_right(sq, ogx, ogy, step);
	else if (sq->angle > 90 && sq->angle < 270)
		comp_left(sq, ogx, ogy, step);
}

void	ft_bts(t_square *sq, float x, float y, float i)
{
	float	decx;
	float	decy;

	decx = x / roundf(x);
	decy = y / roundf(y);
	if (absf(x - roundf(x)) < absf(y - roundf(y)))
	{
		if (decx > 1)
			sq->bts[(int)i] = EAST;
		if (decx < 1)
			sq->bts[(int)i] = WEST;
	}
	else if (absf(x - roundf(x)) > absf(y - roundf(y)))
	{
		if (decy > 1)
			sq->bts[(int)i] = SOUTH;
		if (decy < 1)
			sq->bts[(int)i] = NORTH;
	}
	else
		sq->bts[(int)i] = NONE;
}

float	ft_roundingit(t_square *sq, float *x, float *y, float i)
{
	float	whole;
	float	cx;
	float	cy;
	float	distance;

	cx = *x;
	cy = *y;
	distance = 0;
	if (checkpepe(sq, *x, *y))
	{
		whole = (int)cx;
		cx -= whole;
		cx *= 1000;
		whole = (int)cy;
		cy -= whole;
		cy *= 1000;
		if ((cy >= 975 && cx >= 975) || (cy <= 25 && cx <= 25) || (cy >= 975 && cx <= 25) || (cy <= 25 && cx >= 975))
			distance = (sqrt(abspwr(absf(roundf(*x)) - sq->pcoord.x) + abspwr(absf(roundf(*y)) - sq->pcoord.y)));
	}
	if (sq->map[(int)*y][(int)*x] == '1')
		distance = (sqrt(abspwr(absf(*x) - sq->pcoord.x) + abspwr(absf(*y) - sq->pcoord.y)));
	if (distance)
	{
		ft_bts(sq, *x, *y, i);
		printf("x coord y coord: %f %f\n\n", *x, *y);
	}
	return (distance);
}

void	fix_x(t_square *sq, float *x, float *y, float slope)
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

void	fix_y(t_square *sq, float *x, float *y, float slope)
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
	printf("handle y, \n");
}

void	handle_pope(t_square *sq, float *x, float *y)
{
	printf("handle pope\n");
	if (sq->angle == 0)
		*x = (ceilf(*x + 0.001));
	else if (sq->angle == 180)
		*x = (floorf(*x - 0.001));
	if (sq->angle == 270)
		*y = (ceilf(*y + 0.001));
	else if (sq->angle == 90)
		*y = (floorf(*y - 0.001));
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
			rdx = (ceilf(*x + 0.0001) - *x) * slope;
		else
			rdx = (*x - floorf(*x - 0.0001)) * slope;
		if (sq->angle >= 0 && sq->angle <= 180)
			rdy = (*y - floorf(*y - 0.0001)) / slope;
		else
			rdy = (ceilf(*y + 0.0001) - *y) / slope;
		if (rdx <= rdy)
			fix_x(sq, x, y, slope);
		else
			fix_y(sq, x, y, slope);
	}
	printf("coords: x: %f, y: %f, slope: %f\n", *x, *y, slope);
}

float	zeus(t_square *sq)
{
	float	slope;
	float	x;
	float	y;

	x = sq->pcoord.x;
	y = sq->pcoord.y;
	if (sq->angle == 90 || sq->angle == 270)
		slope = 0;
	else
		slope = tanf(dtr(sq->angle));
	while (!gonetoofar(sq->pcoord, x, y))
	{
		movement(sq, &x, &y, slope);
		if (sq->map[(int)y][(int)x] == '1')
			return (sqrt(abspwr(absf(x) - sq->pcoord.x) + abspwr(absf(y) - sq->pcoord.y)));
	}
	return (-1);
}

void	coneheads(t_square *sq)
{
	float	i;
	float	angle;

	i = 0;
	while (i < sq->winwidth)
	{
		angle = sq->centerangle + (30.0 - ((60.0 / sq->winwidth) * i));
		if (angle < 0)
			angle = 360 + angle;
		else if (angle >= 360)
			angle -= 360;
		sq->angle = angle;
		printf("CALLING ZEUS WITH ANGLE %f\n", angle);
		sq->cone[(int)i] = zeus(sq);
		i++;
	}
}

void	xrayingit(t_square *sq)
{
	float	*cone;
	int		*bts;

	if (sq->coneflag == false)
	{
		cone = malloc((sq->winwidth + 1) * sizeof(float));
		if (!cone)
			die("Malloc fail\n", sq, 0);
		cone[sq->winwidth] = -1;
		bts = malloc((sq->winwidth + 1) * sizeof(int));
		if (!bts)
			die("Malloc fail\n", sq, 0);
		bts[sq->winwidth] = NONE;
		sq->cone = cone;
		sq->bts = bts;
		sq->coneflag = true;
	}
	coneheads(sq);
}
