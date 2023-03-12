/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:57:07 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/28 17:31:17 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

static char	**get_parsed_mat(char *scene_file, t_all *game_struc, int fd)
{
	char	**mat;
	char	**mat_with_border;

	mat = alloc_mat(scene_file, fd, &game_struc->map_data);
	if (!mat)
		return (NULL);
	mat_with_border = add_border(mat, &game_struc->map_data);
	if (!mat_with_border)
	{
		free_double_tab(mat);
		return (NULL);
	}
	if (close(fd) == -1)
	{
		free_double_tab(mat_with_border);
		return (NULL);
	}
	if (!check_valid_scene(scene_file, mat_with_border, game_struc))
	{
		free_double_tab(mat_with_border);
		return (NULL);
	}
	return (mat_with_border);
}

char	**start_parsing(char *scene_file, t_all *game_struc)
{
	int		fd;
	char	**mat;

	fd = init_textures_and_colors(&game_struc->texture_color_data, scene_file);
	if (fd == -1 || fd == -2)
	{
		free_struc_elements(game_struc->texture_color_data);
		return (NULL);
	}
	mat = get_parsed_mat(scene_file, game_struc, fd);
	game_struc->render_data.c_color
		= convert_rgb_to_hexa(game_struc->texture_color_data.c_color);
	game_struc->render_data.f_color
		= convert_rgb_to_hexa(game_struc->texture_color_data.f_color);
	if (!mat || game_struc->render_data.c_color == -1
		|| game_struc->render_data.f_color == -1)
	{
		close(fd);
		ft_print_error("Error\nCheck scene file\n");
		free_struc_elements(game_struc->texture_color_data);
		if (mat)
			free_double_tab(mat);
		return (NULL);
	}
	return (mat);
}
