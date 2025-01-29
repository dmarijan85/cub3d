/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrayzzzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:48:56 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/29 20:32:55 by dmarijan         ###   LAUSANNE.ch       */
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

float	zeus(t_square *sq, int angle)
{
	float	slope;
	float	x;
	float	y;

	x = sq->pcoord.x;
	y = sq->pcoord.y;
	if (angle == 90 || angle == 270)
		slope = 0;
	else
		slope = tanf(angle);
	while (!gonetoofar(sq->pcoord, x, y))
	{
		x += 0.1;
		y = slope * x;
		if (sq->map[(int)y][(int)x] == '1')
			return (sqrt(abs(x - sq->pcoord.x)^2 +abs(y - sq->pcoord.y)^2));
	}
	return (-1);
}

void	coneheads(t_square *sq)
{
	float	*cone;
	int		i;

	cone = malloc(61 * sizeof(float));
	cone[61] = 0;
	i = 0;
	while (i <= 60)
	{
		cone[i] = zeus(sq, sq->centerangle + (30 - i));
		i++;
	}
	sq->cone = cone;
}

void	xrayingit(t_square *sq)
{
	coneheads(sq);
}
