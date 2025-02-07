/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jarvishookthis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:48:33 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/07 19:54:04 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	jarvis_x(float angle, float *x, float *y)
{
	float	step;
	float	slope;

	step = 0.05;
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

	step = 0.05;
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

void	move(t_square *sq, float diff)
{
	float	slope;
	float	tempangle;

	tempangle = (sq->centerangle + diff);
	if (tempangle >= 360)
		tempangle -= 360;
	if (tempangle == 90 || tempangle == 270)
		slope = 0;
	else
		slope = tanf(dtr(tempangle));
	if (absf(slope) > 1 || tempangle == 90 || tempangle == 270)
		jarvis_y(tempangle, &sq->pcoord.x, &sq->pcoord.y);
	else
		jarvis_x(tempangle, &sq->pcoord.x, &sq->pcoord.y);
	printf("player coords x: %f, y: %f\nslope: %f\n tempangle: %f\n\n", sq->pcoord.x, sq->pcoord.y, slope, tempangle);
}

void	hook(void *param)
{
	t_square	*sq;

	sq = param;
	if (mlx_is_key_down(sq->window, MLX_KEY_ESCAPE))
	{
		mlx_close_window(sq->window);
		die("Goodbye!\n", sq, 0);
	}
	if (mlx_is_key_down(sq->window, MLX_KEY_W))
	{
		move(sq, 0);
		if (sq->floppatron)
			mlx_delete_image(sq->window, sq->floppatron);
		xrayingit(sq);
		trump_deluxe(sq);
	}
	if (mlx_is_key_down(sq->window, MLX_KEY_S))
	{
		move(sq, 180);
		if (sq->floppatron)
			mlx_delete_image(sq->window, sq->floppatron);
		xrayingit(sq);
		trump_deluxe(sq);
	}
	if (mlx_is_key_down(sq->window, MLX_KEY_A))
	{
		move(sq, 90);
		if (sq->floppatron)
			mlx_delete_image(sq->window, sq->floppatron);
		xrayingit(sq);
		trump_deluxe(sq);
	}
	if (mlx_is_key_down(sq->window, MLX_KEY_D))
	{
		move(sq, 270);
		if (sq->floppatron)
			mlx_delete_image(sq->window, sq->floppatron);
		xrayingit(sq);
		trump_deluxe(sq);
	}
	if (mlx_is_key_down(sq->window, MLX_KEY_LEFT))
	{
		sq->centerangle += 1;
		if (sq->centerangle >= 360)
			sq->centerangle -= 360;
		if (sq->floppatron)
			mlx_delete_image(sq->window, sq->floppatron);
		xrayingit(sq);
		trump_deluxe(sq);
	}
	if (mlx_is_key_down(sq->window, MLX_KEY_RIGHT))
	{
		sq->centerangle -= 1;
		if (sq->centerangle < 0)
			sq->centerangle += 360;
		if (sq->floppatron)
			mlx_delete_image(sq->window, sq->floppatron);
		xrayingit(sq);
		trump_deluxe(sq);
	}
}
