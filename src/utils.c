/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:06:04 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 15:06:05 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gonetoofar(t_fcoord player, float x, float y)
{
	if ((absf(player.x - x) >= 100) || (absf(player.y - y) >= 100))
		return (1);
	return (0);
}
