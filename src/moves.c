/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:12:10 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 15:12:18 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
