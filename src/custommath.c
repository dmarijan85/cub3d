/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custommath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:05:51 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 15:09:17 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	if (degrees >= 360)
		degrees -= 360;
	if (degrees < 0)
		degrees += 360;
	radians = degrees * (PI / 180.0);
	return (radians);
}

float	safe_rounder(float number, bool ceil)
{
	if (ceil && (number != (int)number))
		number = ceilf(number);
	else if (!ceil && (number != (int)number))
		number = floorf(number);
	else if (ceil && number == (int)number)
		number = ceilf(number + 0.001);
	else if (!ceil && number == (int)number)
		number = floorf(number - 0.001);
	return (number);
}
