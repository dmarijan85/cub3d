/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:48:49 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/17 14:11:52 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//errexit
void	die(char *errmsg, t_square *sq, int fd)
{
	if (errmsg)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(errmsg, 2);
		ft_putstr_fd("\n", 2);
	}
	//free the square
	(void)sq;
	if (fd)
		close(fd);
	exit(1);
}

char	*get_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

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

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	isemptyline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int		ft_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	extend_map(char *str, t_square *sq)
{
	int		i;
	char	**newmap;

	i = 0;
	newmap = malloc(ft_size(sq->map) + 2 * sizeof(char *));
	while (sq->map[i])
	{
		newmap[i] = ft_strdup(sq->map[i]);
		i++;
	}
	array_free(sq->map);
	newmap[i] = str;
	newmap[i + 1] = NULL;
	sq->map = newmap;
}

void	compute_map(char *str, t_square *sq, int fd)
{
	int		i;
	bool	flag;

	flag = false;
	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1')
			flag = true;
		i++;
	}
	if (flag)
		extend_map(str, sq);
	else
		die("No map present in file?!", sq, fd);
}

//parser
int	veggietales(char **argv, t_square *sq)
{
	int		fd;
	char	*str;
	int		i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		die("Map can't be opened (doesn't exist / check permissions)!", sq, fd);
	while (i)
	{
		str = get_next_line(fd);
		if (!str)
			i = 0;
		else
		{
			if (isemptyline(str))
				free(str);
			else
			{
				if (sq->infonumber == 6)
					compute_map(str, sq, fd);
				else
				{
					while (*str == ' ')
						str++;
					if (!ft_strncmp(str, "F " , 2))
					{
						str++;
						while (*str == ' ')
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
								die("Illegal floor RGB! (Should be [0,255])", sq, fd);
							i++;
						}
						sq->infonumber++;
					}
					else if (!ft_strncmp(str, "C " , 2))
					{
						str++;
						while (*str == ' ')
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
					else if (!ft_strncmp(str, "NO ", 3))
					{
						str += 2;
						while (*str == ' ')
							str++;
						sq->no = ft_substr(str, 0, ft_strlen(str));
						sq->infonumber++;
					}
					else if (!ft_strncmp(str, "WE ", 3))
					{
						str += 2;
						while (*str == ' ')
							str++;
						sq->we = ft_substr(str, 0, ft_strlen(str));
						sq->infonumber++;
					}
					else if (!ft_strncmp(str, "EA ", 3))
					{
						str += 2;
						while (*str == ' ')
							str++;
						sq->ea = ft_substr(str, 0, ft_strlen(str));
						sq->infonumber++;
					}
					else if (!ft_strncmp(str, "SO ", 3))
					{
						str += 2;
						while (*str == ' ')
							str++;
						sq->so = ft_substr(str, 0, ft_strlen(str));
						sq->infonumber++;
					}
					else
						die("Don't put illegal shit in my map file you dumb cunt", sq, fd);
					free(str);
				}
			}
		}
	}
	close (fd);
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
		die("Invalid number of arguments", &sq, 0);
	if (iscub(argv[1]) == 0)
		die("Invalid argument (<name>.cub)", &sq, 0);
	sq.map = malloc(1 * sizeof(char *));
	sq.map[0] = NULL;
	veggietales(argv, &sq);
}
