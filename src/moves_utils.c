/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:05:55 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 15:05:57 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
