/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:56:49 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:56:51 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

char	*prepare_border_line(char **mat, int line_index, int trigger, int width)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = ft_calloc(width + 2, sizeof(char));
	if (!new_line)
	{
		free_double_tab(mat);
		return (NULL);
	}
	if (trigger == 1)
	{
		while (i < width + 1)
			new_line[i++] = 2;
	}
	else
	{
		new_line[0] = 2;
		ft_strlcpy(&new_line[1], mat[line_index], width);
		i = ft_strlen(mat[line_index]);
		while (i < width + 1)
			new_line[i++] = 2;
	}
	return (new_line);
}

char	**add_border(char **mat, t_map_data *map_data)
{
	int		i;
	char	**new_mat;

	map_data->map_width = get_map_width(mat);
	new_mat = ft_calloc((map_data->map_height + 3), sizeof(char *));
	if (!new_mat)
		return (NULL);
	i = 1;
	new_mat[0] = prepare_border_line(mat, 0, 1, map_data->map_width);
	if (!new_mat[0])
		return (NULL);
	while (i < map_data->map_height + 1)
	{
		new_mat[i] = prepare_border_line(mat, i - 1, 0, map_data->map_width);
		if (!new_mat[i])
			return (NULL);
		i++;
	}
	new_mat[i] = prepare_border_line(mat, i - 1, 1, map_data->map_width);
	if (!new_mat[i])
		return (NULL);
	free_double_tab(mat);
	return (new_mat);
}

char	**fill_mat(char *line, int fd, char **mat, t_map_data *map_data)
{
	int		i;
	char	*tmp;

	i = 1;
	mat[0] = line;
	while (i < map_data->map_height)
	{
		tmp = get_next_line(fd, 1);
		if (!tmp)
		{
			free_double_tab(mat);
			return (NULL);
		}
		if (ft_strcmp(tmp, "\n") != 0)
			mat[i++] = tmp;
		else
		{
			free_double_tab(mat);
			free(tmp);
			return (NULL);
		}
	}
	return (mat);
}

char	**alloc_mat(char *scene_file, int fd, t_map_data *map_data)
{
	char	**mat;
	char	*line;

	map_data->map_height = get_map_height(fd);
	if (map_data->map_height == -1)
		return (NULL);
	fd = skip_textures_and_colors(scene_file);
	line = get_next_line(fd, 1);
	if (!line)
		return (NULL);
	while (ft_strcmp(line, "\n") == 0)
	{
		free(line);
		line = get_next_line(fd, 1);
		if (!line)
			return (NULL);
	}
	mat = ft_calloc((map_data->map_height + 1), sizeof(char *));
	if (!mat)
		return (NULL);
	mat = fill_mat(line, fd, mat, map_data);
	return (mat);
}
