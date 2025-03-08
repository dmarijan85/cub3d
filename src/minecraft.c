/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minecraft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:08:36 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/08 18:43:19 by dmarijan         ###   LAUSANNE.ch       */
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
	sq->winheight = 900;
	sq->winwidth = 1200;
	sq->coneflag = false;
	sq->floppatron = NULL;
	while (i < 3)
	{
		sq->fc[i] = 0;
		sq->cc[i] = 0;
		i++;
	}
}
