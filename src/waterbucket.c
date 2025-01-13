/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waterbucket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:25:49 by mclaver-          #+#    #+#             */
/*   Updated: 2025/01/13 14:06:51 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	flood_up(t_square *sq, char **map, t_coord player)
{
	t_coord	p;

	if (map[player.y - 1][player.x] != 1
		&& map[player.y - 1][player.x] != -1)
	{
		p.x = player.x;
		p.y = player.y - 1;
		if (ft_isspace(map[p.y][p.x]) || p.y == 0)
			return (1);
		flood_fill(root, map, p);
	}
	return (0);
}

static int	flood_down(t_square *sq, char **map, t_coord player)
{
	t_coord	p;

	if (map[player.y + 1][player.x] != '1'
		&& map[player.y + 1][player.x] != '-')
	{
		p.x = player.x;
		p.y = player.y + 1;
		if (ft_isspace(map[p.y][p.x]) || p.y == sq->mapdepth - 1)
			return (1);
		flood_fill(root, map, p);
	}
	return (0);
}

static int	flood_rite(t_square *sq, char **map, t_coord player)
{
	t_coord	p;

	if (map[player.y][player.x + 1] != 1
		&& map[player.y][player.x + 1] != -1)
	{
		p.x = player.x + 1;
		p.y = player.y;
		if (ft_isspace(map[p.y][p.x]) || p.x == ft_strlen(map[p.y]) - 1)
			return (1);
		flood_fill(root, map, p);
	}
	return (0);
}

static int	flood_left(t_square *sq, char **map, t_coord player)
{
	t_coord	p;

	if (map[player.y][player.x - 1] != 1
		&& map[player.y][player.x - 1] != -1)
	{
		p.x = player.x - 1;
		p.y = player.y;
		if (ft_isspace(map[p.y][p.x]) || p.x == 0)
			return (1);
		flood_fill(root, map, p, floodutils);
	}
	return (0);
}

int	flood_fill(t_square *sq, char **map, t_coord player)
{
	map[player.x][player.y] == '-'
	if (flood_down(root, map, player, floodutils) == 1)
		return (1);
	if (flood_up(root, map, player, floodutils) == 1)
		return (1);
	if (flood_rite(root, map, player, floodutils) == 1)
		return (1);
	if (flood_left(root, map, player, floodutils) == 1)
		return (1);
	return (0);
}
