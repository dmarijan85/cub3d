/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemyman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:06:15 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 16:15:01 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	array_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_printf("%s\n", str[i]);
			get_free(&str[i]);
			i++;
		}
		if (str)
			free(str);
	}
	str = NULL;
}

//errexit
void	die(char *errmsg, t_square *sq, int fd)
{
	int	i;

	i = 0;
	if (errmsg)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(errmsg, 2);
		ft_putstr_fd("\n", 2);
	}
	ft_printf("NO:%s, WE:%s, SO:%s, EA:%s\n", sq->no, sq->we, sq->so, sq->ea);
	while (i < 3)
	{
		ft_printf("CC[%i]:%i, FC[%i]:%i\n", i, sq->cc[i], i, sq->fc[i]);
		i++;
	}
	free(sq->no);
	free(sq->ea);
	free(sq->we);
	free(sq->so);
	if (sq->gnl)
		get_free(&sq->gnl);
	array_free(sq->map);
	if (fd)
		close(fd);
	exit(1);
}
