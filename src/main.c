/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:48:49 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/12 16:15:58 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>

//parser
int	veggietales(char **argv, t_square *sq)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		die("Map can't be opened (doesn't exist / check permissions)!", sq, fd);
	while (42)
	{
		i = 0;
		str = get_next_line(fd);
		sq->gnl = str;
		if (!str)
		{
			if (sq->infonumber != 6)
				die ("Scoundrel! The map is fucking missing shit bro!!!", sq, fd);
			close(fd);
			return (0);
		}
		if (isemptyline(str))
			get_free(&sq->gnl);
		else
		{
			if (sq->infonumber == 6)
				compute_map(str, sq, fd);
			else
			{
				while (ft_isspace(*str))
					str++;
				if (!ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "F\t", 2))
				{
					str++;
					while (ft_isspace(*str))
						str++;
					while ((ft_isalnum(*str) || *str == ',') && i < 3)
					{
						while (ft_isalnum(*str))
						{
							sq->fc[i] *= 10;
							sq->fc[i] += *str - '0';
							str++;
						}
						str++;
						if (sq->fc[i] < 0 || sq->fc[i] > 255)
							die("Illegal floor RGB! (Should [0,255])", sq, fd);
						i++;
					}
					sq->infonumber++;
				}
				else if (!ft_strncmp(str, "C " , 2) || !ft_strncmp(str, "C\t", 2))
				{
					str++;
					while (ft_isspace(*str))
						str++;
					while ((ft_isalnum(*str) || *str == ',') && i < 3)
					{
						while (ft_isalnum(*str))
						{
							sq->cc[i] *= 10;
							sq->cc[i] += *str - '0';
							str++;
						}
						str++;
						if (sq->cc[i] < 0 || sq->cc[i] > 255)
							die("Illegal ceiling RGB! (Should be [0,255])", sq, fd);
						i++;
					}
					sq->infonumber++;
				}
				else if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "NO\t", 3))
				{
					str += 2;
					while (ft_isspace(*str))
						str++;
					sq->no = ft_substr(str, 0, ft_strlen(str) - 1);
					if (!isemptyline(sq->no))
						sq->infonumber++;
					
				}
				else if (!ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "WE\t", 3))
				{
					str += 2;
					while (ft_isspace(*str))
						str++;
					sq->we = ft_substr(str, 0, ft_strlen(str) - 1);
					if (!isemptyline(sq->we))
						sq->infonumber++;
				}
				else if (!ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "EA\t", 3))
				{
					str += 2;
					while (ft_isspace(*str))
						str++;
					sq->ea = ft_substr(str, 0, ft_strlen(str) - 1);
					if (!isemptyline(sq->ea))
						sq->infonumber++;
				}
				else if (!ft_strncmp(str, "SO ", 3) || !ft_strncmp(str, "S\t", 3))
				{
					str += 2;
					while (ft_isspace(*str))
						str++;
					sq->so = ft_substr(str, 0, ft_strlen(str) - 1);
					if (!isemptyline(sq->so))
						sq->infonumber++;
				}
				get_free(&sq->gnl);
			}
		}
	}
	return (0);
}

int	iscub(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".cub\0", ft_strlen(".cub")) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_square	sq;

	minecraft(&sq);
	if (argc != 2)
		die("Invalid number of arguments! <./cub3D 'mappath'>", &sq, 0);
	if (iscub(argv[1]) == 0)
		die("Invalid argument (<name>.cub)", &sq, 0);
	sq.map = malloc(1 * sizeof(char *));
	sq.map[0] = NULL;
	veggietales(argv, &sq);
	mapdeluxe(&sq);
	picture_this(&sq);
	legalize_walls(&sq);
	xrayingit(&sq);
	mlx_loop_hook(sq.window, &hook, &sq);
	mlx_loop(sq.window);
	mlx_terminate(sq.window);
	free(sq.cone);
	die("Program finished", &sq, 0);
}
