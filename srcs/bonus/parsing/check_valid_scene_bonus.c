/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_scene_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:57:19 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:57:21 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

bool	check_file_name(char *scene_file, char *extension)
{
	int	j;

	j = ft_strlen(scene_file) - 4;
	if (ft_strcmp(&scene_file[j], extension) != 0)
		return (false);
	return (true);
}

bool	check_textures_and_colors_elements(t_texture_color_data \
	texture_color_data)
{
	int	i;

	i = 0;
	if (!texture_color_data.no_texture)
		return (false);
	if (!texture_color_data.so_texture)
		return (false);
	if (!texture_color_data.we_texture)
		return (false);
	if (!texture_color_data.ea_texture)
		return (false);
	while (i < 3)
	{
		if (texture_color_data.c_color[i] == -1)
			return (false);
		i++;
	}
	while (i < 3)
	{
		if (texture_color_data.f_color[i] == -1)
			return (false);
		i++;
	}
	return (true);
}

bool	check_valid_scene(char *scene_file, char **mat, t_all *game_struc)
{
	if (!check_file_name(scene_file, ".cub"))
		return (false);
	if (!check_textures_and_colors_elements(game_struc->texture_color_data))
		return (false);
	if (!check_map_content(mat, &game_struc->map_data))
		return (false);
	if (game_struc->map_data.nb_players != 1)
		return (false);
	return (true);
}
