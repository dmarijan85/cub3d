/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iminyourwalls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:11:02 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/08 20:39:18 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdint.h>

uint32_t	get_pixel_info(mlx_image_t *texture, int pixel_index)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (pixel_index < 0)
		return (0);
	r = texture->pixels[pixel_index];
	g = texture->pixels[pixel_index + 1];
	b = texture->pixels[pixel_index + 2];
	a = texture->pixels[pixel_index + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_texture(t_square *sq, mlx_image_t *texture, int i, mlx_image_t *wall)
{
	double	tex_pos;
	int		y;
	int		pixel_index;
	float	height;
	float	y_step;
	int		tex_y;

	height = ((sq->winheight) / (sq->cone[i]));
	y_step = (double)texture->height / height;
	y = (wall->height - height) / 2;
	tex_pos = 0;
	while (height > 0)
	{
		if (y > sq->winheight)
			break ;
		tex_y = (int)tex_pos % texture->height;
		tex_pos += y_step;
		pixel_index = (tex_y * texture->width + (int)sq->hit_coord) * 4;
		if (y >= 0)
			mlx_put_pixel(wall, i, y, get_pixel_info(texture, pixel_index));
		y++;
		height--;
	}
}

//The Brutalist is a 2024 epic period drama film directed and produced by Brady
//Corbet, who co-wrote the screenplay with Mona Fastvold. 
//It stars Adrien Brody as a Hungarian-born Jewish Holocaust survivor who 
//immigrates to the United States, where he struggles to achieve the American 
//Dream until a wealthy client changes his life. Adrien Brody received his
//second ever Oscar's award to best actor.
void	the_brutalist(t_square *sq, int i, mlx_image_t *wall)
{
	float		height;

	if (sq->cone[i] == -1)
		return ;
	height = ((sq->winheight) / (sq->cone[i]));
	if (height > 0 && sq->bts == NORTH)
		draw_texture(sq, sq->nwall, i, wall);
	else if (height > 0 && sq->bts == SOUTH)
		draw_texture(sq, sq->swall, i, wall);
	else if (height > 0 && sq->bts == EAST)
		draw_texture(sq, sq->ewall, i, wall);
	else if (height > 0 && sq->bts == WEST)
		draw_texture(sq, sq->wwall, i, wall);
	else
		return ;
}

//build the wall!!!
void	trump_deluxe(t_square *sq)
{
	int			i;
	mlx_image_t	*wall;

	wall = mlx_new_image(sq->window, sq->winwidth, sq->winheight);
	i = 0;
	while (i < sq->winwidth)
	{
		the_brutalist(sq, i, wall);
		i++;
	}
	mlx_image_to_window(sq->window, wall, 0, 0);
	sq->floppatron = wall;
}
