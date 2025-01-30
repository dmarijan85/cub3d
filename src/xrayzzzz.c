/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrayzzzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:48:56 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/30 15:36:19 by dmarijan         ###   ########.fr       */
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

int	gonetoofar(t_coord player, float x, float y)
{
	if ((abs(player.x - (int)x) >= 20) || (abs(player.y - (int)y) >= 20))
		return (1);
	return (0);
}

float	absf(float num)
{
	if (num < 0)
		num *= -1;
	return (num);
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

float	zeus(t_square *sq, int angle)
{
	float	slope;
	float	x;
	float	y;
	float	step;

	step = 0.01;
	x = sq->pcoord.x;
	y = sq->pcoord.y;
	if (angle == 90 || angle == 270)
		slope = 0;
	else
		slope = tanf(dtr(angle));
	printf("slope %f\n\n", slope);
	while (!gonetoofar(sq->pcoord, x, y))
	{
		printf("x coord: %f\ny coord: %f\n", x, y);
		if (angle < 90 || angle > 270)
			x += step;
		else if (angle > 90 && angle < 270)
			x -= step;
		if (angle == 90)
			y -= step;
		else if (angle == 270)
			y += step;
		else if (angle > 0 && angle < 180)
			y -= absf(slope * step);
		else if (angle > 180 && angle < 360)
			y += absf(slope * step);
		printf("stepped at\nx: %f\ny: %f\nit is: %c\n\n", x, y, sq->map[(int)y][(int)x]);
		if ((int)y < 0)
			y = 0;
		if ((int)x < 0)
			x = 0;
//TODO if y > ft_size(map) : y=ft_size(map)-1, IF x > mapsize mas de lo mismo
		if (sq->map[(int)y][(int)x] == '1')
			return (sqrt(abspwr(absf(x) - sq->pcoord.x) + abspwr(absf(y) - sq->pcoord.y)));
	}
	return (-1);
}

void	coneheads(t_square *sq)
{
	float	*cone;
	int		i;
	int angle;

	cone = malloc(61 * sizeof(float));
	cone[60] = 0;
	i = 0;
	while (i <= 60)
	{
		angle = sq->centerangle + (30 - i);
		if (angle < 0)
			angle = abs(angle);
		else if (angle >= 360)
			angle -= 360;
		printf("-----CENTERANGLE + 30 - %i = %f\n", i, angle);
		cone[i] = zeus(sq, angle);
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
