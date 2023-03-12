/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:56:29 by blevrel           #+#    #+#             */
/*   Updated: 2023/03/07 13:53:30 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

static bool	check_images_status(t_render_data *render_data)
{
	if (!render_data->s_one_image)
		return (false);
	else if (!render_data->s_two_image)
		return (false);
	else if (!render_data->s_three_image)
		return (false);
	else if (!render_data->s_four_image)
		return (false);
	else if (!render_data->s_five_image)
		return (false);
	else if (!render_data->s_six_image)
		return (false);
	else if (!render_data->s_seven_image)
		return (false);
	return (true);
}

static bool	load_sprites(t_texture_color_data texture_color_data,
			t_render_data *render_data, t_window window)
{
	int	x;

	if (!texture_color_data.s_one_sprite || !texture_color_data.s_two_sprite
		|| !texture_color_data.s_three_sprite
		|| !texture_color_data.s_four_sprite
		|| !texture_color_data.s_five_sprite || !texture_color_data.s_six_sprite
		|| !texture_color_data.s_seven_sprite)
		return (false);
	render_data->s_one_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_one_sprite, &x, &x);
	render_data->s_two_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_two_sprite, &x, &x);
	render_data->s_three_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_three_sprite, &x, &x);
	render_data->s_four_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_four_sprite, &x, &x);
	render_data->s_five_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_five_sprite, &x, &x);
	render_data->s_six_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_six_sprite, &x, &x);
	render_data->s_seven_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.s_seven_sprite, &x, &x);
	if (check_images_status(render_data) == false)
		return (false);
	return (true);
}

static bool	init_textures(t_texture_color_data texture_color_data,
			t_render_data *render_data, t_window window)
{
	render_data->no_tex.no_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.no_texture, &render_data->no_tex.width,
			&render_data->no_tex.height);
	render_data->so_tex.so_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.so_texture, &render_data->so_tex.width,
			&render_data->so_tex.height);
	render_data->we_tex.we_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.we_texture, &render_data->we_tex.width,
			&render_data->we_tex.height);
	render_data->ea_tex.ea_image = mlx_xpm_file_to_image(window.mlx,
			texture_color_data.ea_texture, &render_data->ea_tex.width,
			&render_data->ea_tex.height);
	if (texture_color_data.door_texture)
		render_data->door_image = mlx_xpm_file_to_image(window.mlx,
				texture_color_data.door_texture, &render_data->door_width,
				&render_data->door_height);
	if (!load_sprites(texture_color_data, render_data, window)
		|| !render_data->no_tex.no_image || !render_data->so_tex.so_image
		|| !render_data->we_tex.we_image ||!render_data->ea_tex.ea_image
		|| !render_data->door_image)
	{
		ft_print_error("Error\nCheck scene file\n");
		return (false);
	}
	return (true);
}

bool	load_textures(t_texture_color_data texture_color_data,
		t_render_data *render_data, t_window window)
{
	if (init_textures(texture_color_data, render_data, window) == false)
		return (false);
	if (render_data->no_tex.height != render_data->no_tex.width
		|| render_data->so_tex.height != render_data->so_tex.width
		|| render_data->we_tex.height != render_data->we_tex.width
		|| render_data->ea_tex.height != render_data->ea_tex.width)
	{
		ft_print_error("Error\nTextures should be squares");
		ft_print_error(" for animations to display correctly.\n");
		return (false);
	}
	return (true);
}
