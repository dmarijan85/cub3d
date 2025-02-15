/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minecraft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:08:36 by dmarijan          #+#    #+#             */
/*   Updated: 2025/02/15 14:54:14 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minecraft(t_square *sq)
{
	int	i;
	int	*liar;

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
	sq->winheight = 900;
	sq->winwidth = 1200;
	sq->coneflag = false;
	sq->floppatron = NULL;
	sq->iliar = 0;
	while (i < 3)
	{
		sq->fc[i] = 0;
		sq->cc[i] = 0;
		sq->nwall[i] = 50;
		sq->swall[i] = 50;
		sq->ewall[i] = 50;
		sq->wwall[i] = 50;
		i++;
	}
	sq->nwall[2] = 200;
	sq->swall[0] = 200;
	sq->ewall[1] = 200;
	i = 0;
	while (i < sq->winwidth)
	{
		liar = malloc((sq->winwidth + 1) * sizeof(int));
		liar[i] = -1;
		i++;
	}
}
