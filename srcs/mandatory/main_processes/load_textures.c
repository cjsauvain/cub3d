/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:49:33 by blevrel           #+#    #+#             */
/*   Updated: 2023/03/03 16:04:29 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

bool	load_textures(t_texture_color_data texture_color_data,
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
	if (!render_data->no_tex.no_image || !render_data->so_tex.so_image
		|| !render_data->we_tex.we_image ||!render_data->ea_tex.ea_image)
	{
		ft_print_error("Error\nTexture not found\n");
		return (false);
	}
	return (true);
}
