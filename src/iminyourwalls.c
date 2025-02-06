/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iminyourwalls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:11:02 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/06 15:38:02 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//The Brutalist is a 2024 epic period drama film directed and produced by Brady Corbet, who co-wrote the screenplay with Mona Fastvold.[5] It stars Adrien Brody as a Hungarian-born Jewish Holocaust survivor who immigrates to the United States, where he struggles to achieve the American Dream until a wealthy client changes his life.
void	the_brutalist(t_square *sq, mlx_t *window, int i)
{
	mlx_image_t	*wall;
	float		height;

	height = ((sq->cone[i] * -55.38) + 1080);
	printf("height: %f\n", height);
	if (height > 0)
	{
		wall = mlx_new_image(window, 32, height);
		ft_putplane(sq->tempwall, wall);
		mlx_image_to_window(window, wall, 32 * i, (1080 - height) / 2);
	}
}

//build the wall!!!
void	trump_deluxe(t_square *sq)
{
	int	i;

	i = 0;
	while (i <= 60)
	{
		the_brutalist(sq, sq->window, i);	
		i++;
	}
}
