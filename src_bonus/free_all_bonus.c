/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:21:06 by ncasteln          #+#    #+#             */
/*   Updated: 2023/07/18 12:40:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	lst_delnode(void *line)
{
	if (line)
		free(line);
}

static void	free_images(mlx_t *mlx, t_img *img)
{
	mlx_delete_image(mlx, img->p);
	mlx_delete_image(mlx, img->c);
	mlx_delete_image(mlx, img->e);
	mlx_delete_image(mlx, img->n);
	mlx_delete_image(mlx, img->ground);
	mlx_delete_image(mlx, img->wall);
	mlx_delete_image(mlx, img->steps_img);
	// mlx_delete_image(mlx, img->end_img);
}

static void	free_textures(t_txt *txt)
{
	mlx_delete_texture(txt->p);
	mlx_delete_texture(txt->c);
	mlx_delete_texture(txt->e);
	mlx_delete_texture(txt->n);
	mlx_delete_texture(txt->ground);
	mlx_delete_texture(txt->wall);
}

void	free_all(t_state *game)
{
	if (game->map)
		nc_dptr_free(game->map);
	if (game->img)
		free_images(game->mlx, game->img);
	if (game->txt)
		free_textures(game->txt);
	if (game->steps_str)
		free(game->steps_str); // ???????
	// game ----> NULL or free() ?
}
