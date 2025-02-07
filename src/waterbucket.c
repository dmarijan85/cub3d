/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waterbucket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:25:49 by mclaver-          #+#    #+#             */
/*   Updated: 2025/02/07 16:16:34 by dmarijan         ###   LAUSANNE.ch       */
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

int	isokay(t_square *sq, char c, t_coord player)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0' || c == '1')
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			sq->pnbr += 1;
			sq->player = c;
			if (c == 'E')
				sq->centerangle = 0;
			else if (c == 'N')
				sq->centerangle = 90;
			else if (c == 'W')
				sq->centerangle = 180;
			else if (c == 'S')
				sq->centerangle = 270;
			sq->pcoord.x = player.x + 0.5;
			sq->pcoord.y = player.y + 0.5;
		}
		return (1);
	}
	return (0);
}

int	flood_fill(t_square *sq, char **map, t_coord player)
{
	if (!isokay(sq, map[player.y][player.x], player))
		return (1);
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
