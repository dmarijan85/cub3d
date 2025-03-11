/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jarvishookthis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:48:33 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/11 16:55:49 by mclaver-         ###   ########.fr       */
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

void	ft_aaaaaaaaaaaaaaaaaaaa(t_square *sq, float tx, float ty)
{
	sq->pcoord.x = tx;
	sq->pcoord.y = ty;
}

void	move(t_square *sq, float diff)
{
	float	slope;
	float	tempangle;
	float	tx;
	float	ty;

	tx = sq->pcoord.x;
	ty = sq->pcoord.y;
	tempangle = (sq->centerangle + diff);
	if (tempangle >= 360)
		tempangle -= 360;
	if (tempangle == 90 || tempangle == 270)
		slope = 0;
	else
		slope = tanf(dtr(tempangle));
	if (absf(slope) > 1 || tempangle == 90 || tempangle == 270)
		jarvis_y(tempangle, &tx, &ty);
	else
		jarvis_x(tempangle, &tx, &ty);
	if ((sq->map[(int)(ty - (sinf(dtr(tempangle + 5)) / 4))][(int)(tx + \
		(cosf(dtr(tempangle + 5)) / 4))] != '1') && (sq->map[(int) \
		(ty - (sinf(dtr(tempangle - 5)) / 4))][(int)(tx + \
		(cosf(dtr(tempangle - 5)) / 4))] != '1'))
		ft_aaaaaaaaaaaaaaaaaaaa(sq, tx, ty);
}

void	ft_rip_jose_maria_gay_de_liebana(t_square *sq, bool *hookers)
{
	if (mlx_is_key_down(sq->window, MLX_KEY_D))
	{
		move(sq, 270);
		*hookers = true;
	}
	if (mlx_is_key_down(sq->window, MLX_KEY_LEFT))
	{
		sq->centerangle += 1;
		if (sq->centerangle >= 360)
			sq->centerangle -= 360;
		*hookers = true;
	}
	else if (mlx_is_key_down(sq->window, MLX_KEY_RIGHT))
	{
		sq->centerangle -= 1;
		if (sq->centerangle < 0)
			sq->centerangle += 360;
		*hookers = true;
	}
	if (*hookers)
	{
		ft_putplane(sq->fc, sq->cc, sq->floppatron);
		xrayingit(sq);
	}
}

void	ft_gyat(t_square *sq)
{
	mlx_close_window(sq->window);
	die("Goodbye!\n", sq, 0);
}

void	hook(void *param)
{
	t_square	*sq;
	bool		hookers;

	sq = param;
	hookers = false;
	if (mlx_is_key_down(sq->window, MLX_KEY_ESCAPE))
		ft_gyat(sq);
	if (mlx_is_key_down(sq->window, MLX_KEY_W))
	{
		move(sq, 0);
		hookers = true;
	}
	if (mlx_is_key_down(sq->window, MLX_KEY_S))
	{
		move(sq, 180);
		hookers = true;
	}
	if (mlx_is_key_down(sq->window, MLX_KEY_A))
	{
		move(sq, 90);
		hookers = true;
	}
	ft_rip_jose_maria_gay_de_liebana(sq, &hookers);
}
