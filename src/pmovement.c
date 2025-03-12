/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmovement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:38:02 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 15:38:10 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	jarvis_x(float angle, float *x, float *y)
{
	float	step;
	float	slope;

	step = 0.02;
	slope = tanf(dtr(angle));
	if (angle < 90 || angle > 270)
		*x += step;
	else if (angle > 90 && angle < 270)
		*x -= step;
	if (angle > 0 && angle < 180)
		*y -= absf(slope * step);
	else if (angle > 180 && angle < 360)
		*y += absf(slope * step);
}

void	jarvis_y(float angle, float *x, float *y)
{
	float	step;
	float	slope;

	step = 0.02;
	if (angle == 90 || angle == 270)
		slope = 0;
	else
		slope = 1 / tanf(dtr(angle));
	if (angle > 0 && angle < 180)
		*y -= step;
	else if (angle > 180 && angle < 360)
		*y += step;
	if (angle < 90 || angle > 270)
		*x += absf(slope * step);
	else if (angle > 90 && angle < 270)
		*x -= absf(slope * step);
}
