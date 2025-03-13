/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:48:49 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/13 12:08:21 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>

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
		if (eat_the_veggies(sq, str, fd, &i))
			return (1);
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
