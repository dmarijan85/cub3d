/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:48:49 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/30 14:34:46 by dmarijan         ###   LAUSANNE.ch       */
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

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
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

int	ft_size(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i][0])
		i++;
	return (i);
}

void	extend_map(char *str, t_square *sq)
{
	int		i;
	char	**newmap;

	i = 0;
	newmap = malloc((ft_size(sq->map) + 2) * sizeof(char *));
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

/*that weird tmp - 1 size is for newline that gnl returns*/
void	compute_map(char *str, t_square *sq, int fd)
{
	int		i;
	bool	flag;
	char	*tmp;

	flag = false;
	i = 0;
	tmp = malloc((ft_strlen(str)) * sizeof(char));
	tmp[0] = '\0';
	ft_strlcat(tmp, str, ft_strlen(str));
	free(str);
	while (tmp[i])
	{
		if (tmp[i] == '0' || tmp[i] == '1')
			flag = true;
		i++;
	}
	if (flag)
		extend_map(tmp, sq);
	else
		die("No map present in file?!", sq, fd);
}

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
					sq->no = ft_substr(str, 0, ft_strlen(str));
					if (!isemptyline(sq->no))
						sq->infonumber++;
				}
				else if (!ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "WE\t", 3))
				{
					str += 2;
					while (ft_isspace(*str))
						str++;
					sq->we = ft_substr(str, 0, ft_strlen(str));
					if (!isemptyline(sq->we))
						sq->infonumber++;
				}
				else if (!ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "EA\t", 3))
				{
					str += 2;
					while (ft_isspace(*str))
						str++;
					sq->ea = ft_substr(str, 0, ft_strlen(str));
					if (!isemptyline(sq->ea))
						sq->infonumber++;
				}
				else if (!ft_strncmp(str, "SO ", 3) || !ft_strncmp(str, "S\t", 3))
				{
					str += 2;
					while (ft_isspace(*str))
						str++;
					sq->so = ft_substr(str, 0, ft_strlen(str));
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

int	get_longest_line(char **map)
{
	int	longest;
	int	i;

	i = 0;
	longest = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > longest)
			longest = ft_strlen(map[i]);
		i++;
	}
	return (longest);
}

void	check_replace(char *line, int longest, t_square *sq, int pos)
{
	char	*tmp;
	int		i;

	i = 0;
	if ((int)ft_strlen(line) < longest)
	{
		tmp = malloc((longest + 1) * sizeof(char));
		if (!tmp)
			die("Malloc fail", sq, 0);
		while (i < (int)ft_strlen(line))
		{
			tmp[i] = line[i];
			i++;
		}
		while (i < longest)
		{
			tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		free(line);
		sq->map[pos] = tmp;
	}
}

void	waterbucket(t_square *sq, int x, int y)
{
	t_coord	player;
	char	**tmp;
	int		i;

	if (!sq->map || !*sq->map)
		die("Holy shit where is the map buddy?!?!", sq, 0);
	i = 0;
	player.x = x;
	player.y = y;
	tmp = malloc((ft_size(sq->map) + 1) * sizeof(char *));
	while (i < ft_size(sq->map))
	{
		tmp[i] = ft_strdup(sq->map[i]);
		i++;
	}
	tmp[i] = NULL;
	if (flood_fill(sq, tmp, player) || !sq->player || sq->pnbr != 1)
	{
		array_free(tmp);
		die("Holy shit lois the map is illegal as fuck bro", sq, 0);
	}
	array_free(tmp);
}

void	mapdeluxe(t_square *sq)
{
	int	longest;
	int	i;
	int	j;

	i = 0;
	j = 0;
	longest = get_longest_line(sq->map);
	while (sq->map[i])
	{
		check_replace(sq->map[i], longest, sq, i);
		i++;
	}
	i = 0;
	while (sq->map[i] && sq->map[i][j] != '0')
	{
		j = 0;
		while (sq->map[i][j] && sq->map[i][j] != '0')
			j++;
		if (sq->map[i][j] == '0')
			break ;
		i++;
	}
	if (!sq->map[i] || !sq->map[i][j])
		die("Holy shit lois this map doesnt even have a single floor!", sq, 0);
	waterbucket(sq, j, i);
}

int	main(int argc, char **argv)
{
	t_square	sq;
//	mlx_t		*window;

	minecraft(&sq);
	if (argc != 2)
		die("Invalid number of arguments", &sq, 0);
	if (iscub(argv[1]) == 0)
		die("Invalid argument (<name>.cub)", &sq, 0);
	sq.map = malloc(1 * sizeof(char *));
	sq.map[0] = NULL;
	veggietales(argv, &sq);
	mapdeluxe(&sq);
//	window = mlx_init(1920, 1080, "cub3d", false);
//	if (!window)
//		die("Window blew up...", &sq, 0);
	xrayingit(&sq);
	free(sq.cone);
//	mlx_loop(window);
//	mlx_terminate(window);
	die("Program finished", &sq, 0);
}
