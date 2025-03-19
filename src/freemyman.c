/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemyman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:06:15 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/19 16:36:37 by dmarijan         ###   LAUSANNE.ch       */
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
			get_free(&str[i]);
			i++;
		}
		if (str)
			free(str);
	}
	str = NULL;
}

void	wallbrained(t_square *sq, int wall, char *tmp)
{
	if (wall == NORTH && sq->no)
		free(tmp);
	else if (wall == SOUTH && sq->so)
		free(tmp);
	else if (wall == EAST && sq->ea)
		free(tmp);
	else if (wall == WEST && sq->we)
		free(tmp);
}

void	puzzlebrained(t_square *sq)
{
	if (sq->nwall)
		mlx_delete_image(sq->window, sq->nwall);
	if (sq->swall)
		mlx_delete_image(sq->window, sq->swall);
	if (sq->ewall)
		mlx_delete_image(sq->window, sq->ewall);
	if (sq->wwall)
		mlx_delete_image(sq->window, sq->wwall);
	if (sq->floppatron)
		mlx_delete_image(sq->window, sq->floppatron);
	if (sq->ntext)
		mlx_delete_texture(sq->ntext);
	if (sq->etext)
		mlx_delete_texture(sq->etext);
	if (sq->wtext)
		mlx_delete_texture(sq->wtext);
	if (sq->stext)
		mlx_delete_texture(sq->stext);
	if (sq->gnl)
		get_free(&sq->gnl);
}

void	die(char *errmsg, t_square *sq, int fd)
{
	if (errmsg)
	{
		if (ft_strncmp(errmsg, "Goodbye!", 10))
			ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(errmsg, 2);
		ft_putstr_fd("\n", 2);
	}
	free(sq->no);
	free(sq->ea);
	free(sq->we);
	free(sq->so);
	array_free(sq->map);
	if (fd)
		close(fd);
	if (!ft_strncmp(errmsg, "Goodbye!", 10))
		exit(0);
	exit(1);
}
