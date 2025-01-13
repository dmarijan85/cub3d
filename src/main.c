/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:48:49 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/10 19:55:42 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//errexit
void	die(char *errmsg, t_square *sq)
{
	if (errmsg)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(errmsg, 2);
		ft_putstr_fd("\n", 2);
	}
	//free the square
	exit(1);
}

int	isnowe(char c)
{
	if (c == 'N' || c == 'O' || c == 'W' || 
}

//parser
int	veggietales(char **argv, t_square *sq)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		die("Map can't be opened (doesn't exist / check permissions)!");
	while (fd)
	{
		str = get_next_line(fd);
		if (!str)
			;//root_destroy(root, "map_init(): read()", errno);
		else
		{
			while (*str == ' ')
				str++;
			if (!ft_strncmp(str, "F " , 2))
			{
				str++;
				while (*str == ' ')
					str++;
				while ((ft_isnum(*str) || *str == ',') && i < 3)
				{
					while (ft_isnum(*str))
					{
						sq->fc[i] *= 10;
						sq->fc[i] += *str - '0';
						str++;
					}
					str++;
					if (sq->fc[i] < 0 || sq->fc[i] > 255)
						die("Illegal floor RGB! (Should be [0,255])", sq)
					i++;
				}
			}
			else if (!ft_strncmp(str, "C " , 2))
			{
				str++;
				while (*str == ' ')
					str++;
				while ((ft_isnum(*str) || *str == ',') && i < 3)
				{
					while (ft_isnum(*str))
					{
						sq->cc[i] *= 10;
						sq->cc[i] += *str - '0';
						str++;
					}
					str++;
					if (sq->cc[i] < 0 || sq->cc[i] > 255)
						die("Illegal ceiling RGB! (Should be [0,255])", sq)
					i++;
				}
			}
			else if (!ft_strncmp(str, "NO ", 3))
			{
				str += 2;
				while (*str == ' ')
					str++;
				sq->no = ft_substr(str, 0, ft_strlen(str));
			}
			else if (!ft_strncmp(str, "WE ", 3))
			{
				str += 2;
				while (*str == ' ')
					str++;
				sq->we = ft_substr(str, 0, ft_strlen(str));
			}
			else if (!ft_strncmp(str, "EA ", 3))
			{
				str += 2;
				while (*str == ' ')
					str++;
				sq->ea = ft_substr(str, 0, ft_strlen(str));
			}
			else if (!ft_strncmp(str, "SO ", 3))
			{
				str += 2;
				while (*str == ' ')
					str++;
				sq->so = ft_substr(str, 0, ft_strlen(str));
			}
			else
				die("Don't put illegal shit in my map file you dumb cunt", sq);
		}
		free(str);

	}
	//there has to be a valid map after everything else
	//if first char is a 1, say its good and keep going

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
	t_square	*sq;

	if (argc != 2)
		die("Invalid number of arguments", sq);
	if (iscub(argv[1]) == 0)
		die("Invalid argument (<name>.cub)", sq);
	veggietales(argv, sq);
}
