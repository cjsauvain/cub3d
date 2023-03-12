/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:48:38 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:48:40 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	destroy_images(void *mlx, t_render_data render_data,
	t_render_images render_images)
{
	if (render_data.no_tex.no_image)
		mlx_destroy_image(mlx, render_data.no_tex.no_image);
	if (render_data.so_tex.so_image)
		mlx_destroy_image(mlx, render_data.so_tex.so_image);
	if (render_data.we_tex.we_image)
		mlx_destroy_image(mlx, render_data.we_tex.we_image);
	if (render_data.ea_tex.ea_image)
		mlx_destroy_image(mlx, render_data.ea_tex.ea_image);
	if (render_images.minimap_render.img)
		mlx_destroy_image(mlx, render_images.minimap_render.img);
	if (render_images.window_render.img)
		mlx_destroy_image(mlx, render_images.window_render.img);
}

static void	destroy_tex_images(void *mlx, t_render_data render_data)
{
	if (render_data.no_tex.no_image)
		mlx_destroy_image(mlx, render_data.no_tex.no_image);
	if (render_data.so_tex.so_image)
		mlx_destroy_image(mlx, render_data.so_tex.so_image);
	if (render_data.we_tex.we_image)
		mlx_destroy_image(mlx, render_data.we_tex.we_image);
	if (render_data.ea_tex.ea_image)
		mlx_destroy_image(mlx, render_data.ea_tex.ea_image);
}

int	destroy_tex_not_found(t_all *game_struct)
{
	free_double_tab(game_struct->mat);
	free_struc_elements(game_struct->texture_color_data);
	destroy_tex_images(game_struct->window.mlx, game_struct->render_data);
	mlx_destroy_display(game_struct->window.mlx);
	free(game_struct->window.mlx);
	exit(1);
}

int	destroy(t_all *game_struct)
{
	free_double_tab(game_struct->mat);
	free_struc_elements(game_struct->texture_color_data);
	mlx_destroy_window(game_struct->window.mlx, game_struct->window.win_ptr);
	destroy_images(game_struct->window.mlx, game_struct->render_data,
		game_struct->render_images);
	mlx_loop_end(game_struct->window.mlx);
	mlx_destroy_display(game_struct->window.mlx);
	free(game_struct->window.mlx);
	exit(1);
}
