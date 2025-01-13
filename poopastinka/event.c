/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:40:56 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/24 11:42:13 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_root	*root;

	root = (t_root *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		root_destroy(root, 0, 0);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		root->game->player_up = 1;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		root->game->player_down = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		root->game->player_left = 1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		root->game->player_right = 1;
	update(root);
}

void	close_window(void *param)
{
	t_root	*root;

	root = (t_root *)param;
	root_destroy(root, 0, 0);
	exit(EXIT_SUCCESS);
}
