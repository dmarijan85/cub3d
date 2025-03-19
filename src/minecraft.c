/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minecraft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:08:36 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/19 15:16:17 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	puzzlehead(t_square *sq)
{
	sq->floppatron = NULL;
	sq->nwall = NULL;
	sq->ewall = NULL;
	sq->wwall = NULL;
	sq->swall = NULL;
	sq->ntext = NULL;
	sq->stext = NULL;
	sq->wtext = NULL;
	sq->etext = NULL;
	sq->no = NULL;
	sq->so = NULL;
	sq->we = NULL;
	sq->ea = NULL;
	sq->map = NULL;
}

void	minecraft(t_square *sq)
{
	int	i;

	i = 0;
	sq->mapdepth = 0;
	sq->infonumber = 0;
	sq->gnl = NULL;
	sq->player = '\0';
	sq->centerangle = 0;
	sq->pnbr = 0;
	sq->winheight = 900;
	sq->winwidth = 1200;
	sq->coneflag = false;
	puzzlehead(sq);
	while (i < 3)
	{
		sq->fc[i] = 0;
		sq->cc[i] = 0;
		i++;
	}
}
