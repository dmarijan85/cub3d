/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minecraft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:08:36 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/01 19:22:15 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minecraft(t_square *sq)
{
	int	i;

	i = 0;
	sq->no = NULL;
	sq->so = NULL;
	sq->we = NULL;
	sq->ea = NULL;
	sq->map = NULL;
	sq->mapdepth = 0;
	sq->infonumber = 0;
	sq->gnl = NULL;
	sq->player = '\0';
	sq->centerangle = 0;
	sq->pnbr = 0;
	sq->slope = 0;
	while (i < 3)
	{
		sq->fc[i] = 0;
		sq->cc[i] = 0;
		i++;
	}
}
