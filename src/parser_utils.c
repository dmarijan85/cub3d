/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:11:15 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/14 08:47:56 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	legalize_walls(t_square *sq)
{
	if (!access(sq->no, R_OK) && !access(sq->so, R_OK) && !access(sq->ea, R_OK) \
		&& !access(sq->we, R_OK))
	{
		sq->ntext = mlx_load_png(sq->no);
		sq->stext = mlx_load_png(sq->so);
		sq->etext = mlx_load_png(sq->ea);
		sq->wtext = mlx_load_png(sq->we);
		if (!sq->ntext || !sq->stext || !sq->wtext || !sq->etext)
			die("Error loading textures", sq, 0);
		sq->nwall = mlx_texture_to_image(sq->window, sq->ntext);
		sq->ewall = mlx_texture_to_image(sq->window, sq->etext);
		sq->wwall = mlx_texture_to_image(sq->window, sq->wtext);
		sq->swall = mlx_texture_to_image(sq->window, sq->stext);
	}
	else
		die("Mf sent me bogus textures :skull:", sq, 0);
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
		if (sq->pnbr != 1)
			printf("pnbr = %i\n", sq->pnbr);
		die("Holy shit lois the map is illegal as fuck bro", sq, 0);
	}
	array_free(tmp);
}
