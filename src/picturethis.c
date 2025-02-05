/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picturethis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:22:24 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/03 14:29:09 by dmarijan         ###   LAUSANNE.ch       */
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

void ft_putplane(int *rgb, mlx_image_t *image)
{
	uint32_t	i;
	uint32_t	y;

	i = 0;
	while (i < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			mlx_put_pixel(image, i, y, get_colour(rgb));
			y++;
		}
		i++;
	}
}
void	picture_this(t_square *sq)
{
	mlx_t		*window;
	mlx_image_t	*floor;
	mlx_image_t	*ceiling;

	window = mlx_init(1920, 1080, "cub3d", false);
	if (!window)
		die("Window blew up...", sq, 0);
	floor = mlx_new_image(window, 1920, 540);
	ceiling = mlx_new_image(window, 1920, 540);
	mlx_image_to_window(window, ceiling, 0, 0);
	mlx_image_to_window(window, floor, 0, 540);
	ft_putplane(sq->fc, floor);
	ft_putplane(sq->cc, ceiling);
	mlx_loop(window);
	mlx_terminate(window);
}
