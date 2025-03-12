/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:06:04 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 15:26:55 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gonetoofar(t_fcoord player, float x, float y)
{
	if ((absf(player.x - x) >= 100) || (absf(player.y - y) >= 100))
		return (1);
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
			sq->pcoord.x = ((player.x) + 0.5);
			sq->pcoord.y = ((player.y) + 0.5);
		}
		return (1);
	}
	return (0);
}
