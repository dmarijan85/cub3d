/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:08:37 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/13 11:44:43 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
