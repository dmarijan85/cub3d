/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:09:25 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/23 18:37:33 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	root_destroy(t_root *root, char *errmsg, int errnum)
{
	if (root != 0)
	{
		if (root->ground != 0)
			mlx_delete_image(root->mlx, root->ground);
		if (root->wall != 0)
			mlx_delete_image(root->mlx, root->wall);
		if (root->coll != 0)
			mlx_delete_image(root->mlx, root->coll);
		if (root->exit != 0)
			mlx_delete_image(root->mlx, root->exit);
		if (root->player != 0)
			mlx_delete_image(root->mlx, root->player);
		if (root->mlx_img != 0)
			mlx_delete_image(root->mlx, root->mlx_img);
		if (root->mlx != 0)
			mlx_terminate(root->mlx);
		if (root->game != 0)
			game_destroy(root->game);
		free(root);
	}
	die(errmsg, errnum);
}

void	texture_load(mlx_t *mlx, mlx_image_t **img, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (texture == 0)
		root_destroy(0, "mlx_load_png(): can't load texture", 0);
	*img = mlx_texture_to_image(mlx, texture);
	if (*img == 0)
		root_destroy(0, "mlx_texture_to_image(): can't load texture to image", \
		0);
	mlx_delete_texture(texture);
}

static void	texture_init(t_root *root)
{
	texture_load(root->mlx, &root->player, "textures/idle1.png");
	texture_load(root->mlx, &root->exit, "textures/fort.png");
	texture_load(root->mlx, &root->coll, "textures/bag.png");
	texture_load(root->mlx, &root->wall, "textures/woods.png");
	texture_load(root->mlx, &root->ground, "textures/grass.png");
}

static void	renderer_init(t_root *root)
{
	root->mlx = mlx_init(root->game->width * 100,
			root->game->height * 100, "so_long", false);
	if (root->mlx == 0)
		root_destroy(root, "mlx_init(): can't load mlx", 0);
	root->mlx_img = mlx_new_image(root->mlx, root->game->width * 100,
			root->game->height * 100);
	if (root->mlx_img == 0)
		root_destroy(root, "mlx_new_image(): can't create an image", 0);
}

t_root	*root_init(char *filename)
{
	t_root			*root;

	root = (t_root *)malloc(sizeof(t_root));
	if (root == 0)
		root_destroy(0, "root_init(): malloc()", errno);
	root->game = 0;
	root->mlx = 0;
	root->mlx_img = 0;
	root->player = 0;
	root->exit = 0;
	root->coll = 0;
	root->wall = 0;
	root->ground = 0;
	game_init(root, filename);
	renderer_init(root);
	texture_init(root);
	return (root);
}
