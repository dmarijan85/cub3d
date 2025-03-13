/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_the_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:07:21 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/13 12:07:50 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	eat_the_floor(t_square *sq, char *str, int fd, int *i)
{
	str++;
	while (ft_isspace(*str))
		str++;
	while ((ft_isalnum(*str) || *str == ',') && *i < 3)
	{
		while (ft_isalnum(*str))
		{
			sq->fc[*i] *= 10;
			sq->fc[*i] += *str - '0';
			str++;
		}
		str++;
		if (sq->fc[*i] < 0 || sq->fc[*i] > 255)
			die("Illegal floor RGB! (Should [0,255])", sq, fd);
		(*i)++;
	}
	sq->infonumber++;
}

void	eat_the_ceiling(t_square *sq, char *str, int fd, int *i)
{
	str++;
	while (ft_isspace(*str))
		str++;
	while ((ft_isalnum(*str) || *str == ',') && *i < 3)
	{
		while (ft_isalnum(*str))
		{
			sq->cc[*i] *= 10;
			sq->cc[*i] += *str - '0';
			str++;
		}
		str++;
		if (sq->cc[*i] < 0 || sq->cc[*i] > 255)
			die("Illegal ceiling RGB! (Should be [0,255])", sq, fd);
		(*i)++;
	}
	sq->infonumber++;
}

void	eat_the_walls(t_square *sq, char *str, int wall)
{
	char	*tmp;

	str += 2;
	while (ft_isspace(*str))
		str++;
	tmp = ft_substr(str, 0, ft_strlen(str) - 1);
	if (wall == NORTH)
		sq->no = tmp;
	else if (wall == SOUTH)
		sq->so = tmp;
	else if (wall == EAST)
		sq->ea = tmp;
	else if (wall == WEST)
		sq->we = tmp;
	if (!isemptyline(tmp))
		sq->infonumber++;
}

void	eat_the_world(t_square *sq, char *str, int fd, int *i)
{
	while (ft_isspace(*str))
		str++;
	if (!ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "F\t", 2))
		eat_the_floor(sq, str, fd, i);
	else if (!ft_strncmp(str, "C ", 2) || !ft_strncmp(str, "C\t", 2))
		eat_the_ceiling(sq, str, fd, i);
	else if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "NO\t", 3))
		eat_the_walls(sq, str, NORTH);
	else if (!ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "WE\t", 3))
		eat_the_walls(sq, str, WEST);
	else if (!ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "EA\t", 3))
		eat_the_walls(sq, str, EAST);
	else if (!ft_strncmp(str, "SO ", 3) || !ft_strncmp(str, "S\t", 3))
		eat_the_walls(sq, str, SOUTH);
	get_free(&sq->gnl);
}

int	eat_the_veggies(t_square *sq, char *str, int fd, int *i)
{
	if (!str)
	{
		if (sq->infonumber != 6)
			die("Scoundrel! The map is fucking missing shit bro!!!", sq, fd);
		close(fd);
		return (1);
	}
	if (isemptyline(str))
		get_free(&sq->gnl);
	else
	{
		if (sq->infonumber == 6)
			compute_map(str, sq, fd);
		else
			eat_the_world(sq, str, fd, i);
	}
	return (0);
}
