/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picturethis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:22:24 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/08 20:10:20 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_acolour(int alpha, int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8) | alpha);
}

uint32_t	get_colour(int *color)
{
	return (get_acolour(255, color[0], color[1], color[2]));
}

void	ft_putplane(int *fcrgb, int *ccrgb, mlx_image_t *image)
{
	uint32_t	i;
	uint32_t	y;

	i = 0;
	while (i < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			if (y < image->height / 2)
				mlx_put_pixel(image, i, y, get_colour(ccrgb));
			else
				mlx_put_pixel(image, i, y, get_colour(fcrgb));
			y++;
		}
		i++;
	}
}

void	picture_this(t_square *sq)
{
	mlx_t		*window;
	mlx_image_t	*wall;

	window = mlx_init(sq->winwidth, sq->winheight, "cub3d", false);
	if (!window)
		die("Window blew up...", sq, 0);
	wall = mlx_new_image(window, sq->winwidth, sq->winheight);
	mlx_image_to_window(window, wall, 0, 0);
	ft_putplane(sq->fc, sq->cc, wall);
	sq->window = window;
	sq->floppatron = wall;
}
