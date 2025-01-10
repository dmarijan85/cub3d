/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:25:49 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/25 19:34:05 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_down(t_root *root, int **map, t_coord player, t_flood *floodutils)
{
	t_coord	p;

	if (player.y > 0 && map[player.y - 1][player.x] != 1
		&& map[player.y - 1][player.x] != -1)
	{
		p.x = player.x;
		p.y = player.y - 1;
		flood_fill(root, map, p, floodutils);
	}
}

void	flood_up(t_root *root, int **map, t_coord player, t_flood *floodutils)
{
	t_coord	p;

	if ((player.y < (root->game->height - 1))
		&& map[player.y + 1][player.x] != 1
		&& map[player.y + 1][player.x] != -1)
	{
		p.x = player.x;
		p.y = player.y + 1;
		flood_fill(root, map, p, floodutils);
	}
}

void	flood_rite(t_root *root, int **map, t_coord player, t_flood *floodutils)
{
	t_coord	p;

	if ((player.x < (root->game->width - 1))
		&& map[player.y][player.x + 1] != 1
		&& map[player.y][player.x + 1] != -1)
	{
		p.x = player.x + 1;
		p.y = player.y;
		flood_fill(root, map, p, floodutils);
	}
}

void	flood_left(t_root *root, int **map, t_coord player, t_flood *floodutils)
{
	t_coord	p;

	if (player.x > 0 && map[player.y][player.x - 1] != 1
		&& map[player.y][player.x - 1] != -1)
	{
		p.x = player.x - 1;
		p.y = player.y;
		flood_fill(root, map, p, floodutils);
	}
}

int	flood_fill(t_root *root, int **map, t_coord player, t_flood *floodutils)
{
	char	c;

	c = map[player.y][player.x];
	map[player.y][player.x] = -1;
	if (c == 3)
		floodutils->exit = 1;
	if (c == 4)
		floodutils->collect++;
	flood_down(root, map, player, floodutils);
	flood_up(root, map, player, floodutils);
	flood_rite(root, map, player, floodutils);
	flood_left(root, map, player, floodutils);
	if (floodutils->collect == root->game->count_coll && floodutils->exit == 1)
		return (1);
	return (0);
}
