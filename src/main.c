/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:06:50 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/24 11:03:40 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	die(char *errmsg, int errnum)
{
	if (errmsg != 0 || errnum != 0)
		ft_putendl_fd("Error", 2);
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
	if (errmsg != 0 && errnum != 0)
		ft_putstr_fd(": ", 2);
	if (errnum != 0)
		ft_putstr_fd(strerror(errnum), 2);
	if (errmsg != 0 || errnum != 0)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}

int	isber(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", ft_strlen(".ber")) != 0)
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_root			*root;

	if (ac != 2)
		die("invalid number of arguments", 0);
	if (isber(av[1]) == 0)
		die("invalid argument (<name>.ber)", 0);
	root = root_init(av[1]);
	draw(root);
	mlx_key_hook(root->mlx, key_press, root);
	mlx_close_hook(root->mlx, &close_window, root);
	mlx_loop(root->mlx);
	root_destroy(root, 0, 0);
	return (0);
}
