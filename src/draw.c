/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:40:23 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/21 21:29:42 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_square(t_root *root, mlx_image_t *image, int x, int y)
{
	if (!image)
	{
		root_destroy(root, "Failed to create image from texture", 0);
		return ;
	}
	mlx_image_to_window(root->mlx, image, x, y);
}

static void	draw_env(t_root *root, int i, int j)
{
	int				k;

	if (root->game->exit.x == i && root->game->exit.y == j)
		draw_square(root, root->exit, i * 100, j * 100);
	k = -1;
	while (++k < root->game->count_coll)
		if (root->game->coll[k].x == i && root->game->coll[k].y == j)
			draw_square(root, root->coll, i * 100, j * 100);
	if (root->game->player.x == i && root->game->player.y == j)
		draw_square(root, root->player, i * 100, j * 100);
}

void	draw(t_root *root)
{
	int				i;
	int				j;

	j = 0;
	while (j < root->game->height)
	{
		i = 0;
		while (i < root->game->width)
		{
			if (root->game->map[j][i] == 1)
				draw_square(root, root->wall, i * 100, j * 100);
			else
				draw_square(root, root->ground, i * 100, j * 100);
			draw_env(root, i, j);
			i++;
		}
		j++;
	}
}
