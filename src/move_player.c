/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:42:35 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/25 15:48:07 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_root *root, int x, int y)
{
	texture_load(root->mlx, &root->player, "textures/mup.png");
	if (root->game->map[y - 1][x] != 1)
		root->game->player.y -= 1;
	root->game->player_up = 0;
}

void	move_down(t_root *root, int x, int y)
{
	texture_load(root->mlx, &root->player, "textures/mdown.png");
	if (root->game->map[y + 1][x] != 1)
		root->game->player.y += 1;
	root->game->player_down = 0;
}

void	move_left(t_root *root, int x, int y)
{
	texture_load(root->mlx, &root->player, "textures/mleft.png");
	if (root->game->map[y][x - 1] != 1)
		root->game->player.x -= 1;
	root->game->player_left = 0;
}

void	move_right(t_root *root, int x, int y)
{
	texture_load(root->mlx, &root->player, "textures/mright.png");
	if (root->game->map[y][x + 1] != 1)
		root->game->player.x += 1;
	root->game->player_right = 0;
}
