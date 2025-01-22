/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minecraft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:08:36 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/22 12:54:40 by SET YOUR USER    ###   LAUSANNE.ch       */
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
	while (i < 3)
	{
		sq->fc[i] = 0;
		sq->cc[i] = 0;
		i++;
	}
}
