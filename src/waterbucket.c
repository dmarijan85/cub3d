/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waterbucket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:25:49 by mclaver-          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:30 by SET YOUR USER    ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	flood_up(t_square *sq, char **map, t_coord player)
{
	t_coord	p;

	if (player.y == 0)
		return (1);
	if (map[player.y - 1][player.x] != '1')
	{
		p.x = player.x;
		p.y = player.y - 1;
		if (p.y <= 0 || ft_isspace(map[p.y][p.x]))
			return (1);
		if (flood_fill(sq, map, p))
			return (1);
	}
	return (0);
}

static int	flood_down(t_square *sq, char **map, t_coord player)
{
	t_coord	p;

	if (player.y == ft_size(map))
		return (1);
	if (map[player.y + 1][player.x] != '1')
	{
		p.x = player.x;
		p.y = player.y + 1;
		if (p.y == ft_size(map) - 1 || ft_isspace(map[p.y][p.x]))
			return (1);
		if (flood_fill(sq, map, p))
			return (1);
	}
	return (0);
}

static int	flood_rite(t_square *sq, char **map, t_coord player)
{
	t_coord	p;

	if (player.x == (int)ft_strlen(map[player.y]))
		return (1);
	if (map[player.y][player.x + 1] != '1')
	{
		p.x = player.x + 1;
		p.y = player.y;
		if (p.x == (int)ft_strlen(map[p.y]) - 1 || ft_isspace(map[p.y][p.x]))
			return (1);
		if (flood_fill(sq, map, p))
			return (1);
	}
	return (0);
}

static int	flood_left(t_square *sq, char **map, t_coord player)
{
	t_coord	p;

	if (player.x == 0)
		return (1);
	if (map[player.y][player.x - 1] != '1')
	{
		p.x = player.x - 1;
		p.y = player.y;
		if (p.x == 0 || ft_isspace(map[p.y][p.x]))
			return (1);
		if (flood_fill(sq, map, p))
			return (1);
	}
	return (0);
}

int	flood_fill(t_square *sq, char **map, t_coord player)
{
	map[player.y][player.x] = '1';
	if (flood_down(sq, map, player) == 1)
		return (1);
	if (flood_up(sq, map, player) == 1)
		return (1);
	if (flood_rite(sq, map, player) == 1)
		return (1);
	if (flood_left(sq, map, player) == 1)
		return (1);
	return (0);
}
