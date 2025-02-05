/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrayzzzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:48:56 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/03 12:53:57 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

/*

1 - Decidir un angulo pal cono de vision

	DEPTH PERCEPTION

	para cada angulo:

	-   1
	 |  1
	  ->1 oops
111111111


*/
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

float	big_floppa_returns(t_square *sq, float x, float y, float step)
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
	if (sq->angle > 0 && sq->angle < 180)
		y -= step;
	else if (sq->angle > 180 && sq->angle < 360)
		y += step;
	if (sq->angle < 90 || sq->angle > 270)
		x += absf(slope * step);
	else if (sq->angle > 90 && sq->angle < 270)
		x -= absf(slope * step);
	if (((int)x != (int)xog || (int)y != (int)yog) && sq->map[(int)y][(int)x] == '1')
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
	if (((int)x != (int)xog || (int)y != (int)yog) && sq->map[(int)y][(int)x] == '1')
		return (big_floppa(sq, xog, yog, step / 2));
	if (step > 0.01)
		return (step);
	return (0.01);
}

void	move_x(t_square *sq, int angle, float *x, float *y)
{
	float	step;
	float	slope;

	slope = tanf(dtr(angle));
	step = big_floppa(sq, *x, *y, 1);
	if (angle < 90 || angle > 270)
		*x += step;
	else if (angle > 90 && angle < 270)
		*x -= step;
	if (angle > 0 && angle < 180)
		*y -= absf(slope * step);
	else if (angle > 180 && angle < 360)
		*y += absf(slope * step);
}

void	move_y(t_square *sq, int angle, float *x, float *y)
{
	float	step;
	float	slope;

	if (angle == 90 || angle == 270)
		slope = 0;
	else
		slope = 1 / tanf(dtr(angle));
	step = big_floppa_returns(sq, *x, *y, 1);
	if (angle > 0 && angle < 180)
		*y -= step;
	else if (angle > 180 && angle < 360)
		*y += step;
	if (angle < 90 || angle > 270)
		*x += absf(slope * step);
	else if (angle > 90 && angle < 270)
		*x -= absf(slope * step);
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
//	printf("player: x: %f, y: %f, slope %f\n\n", sq->pcoord.x, sq->pcoord.y, slope);
	while (!gonetoofar(sq->pcoord, x, y))
	{
		if (absf(slope) > 1 || sq->angle == 90 || sq->angle == 270)
			move_y(sq, sq->angle, &x, &y);
		else
			move_x(sq, sq->angle, &x, &y);
		if (sq->map[(int)y][(int)x] == '1')
			return (sqrt(abspwr(absf(x) - sq->pcoord.x) + abspwr(absf(y) - sq->pcoord.y)));
	}
	return (-1);
}

void	coneheads(t_square *sq)
{
	float	*cone;
	int		i;
	int		angle;

	cone = malloc(61 * sizeof(float));
	cone[60] = 0;
	i = 0;
	while (i <= 60)
	{
		angle = sq->centerangle + (30 - i);
		if (angle < 0)
			angle = 360 + angle;
		else if (angle >= 360)
			angle -= 360;
//		printf("-----CENTERANGLE + 30 - %i = %i\n", i, angle);
		sq->angle = angle;
		cone[i] = zeus(sq);
		i++;
	}
	sq->cone = cone;
}

void	xrayingit(t_square *sq)
{
	coneheads(sq);
	int	i;
	i = 0;
	while (i <= 60)
	{
		printf("Cone in [%i], angle %f: %f\n", i, sq->centerangle + (30 - i), sq->cone[i]);
		i++;
	}
}
