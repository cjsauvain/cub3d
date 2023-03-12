/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_and_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:50:30 by blevrel           #+#    #+#             */
/*   Updated: 2023/03/09 13:19:41 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static int	check_ext(char **textures)
{
	char	**splitted_textures;
	int		len_textures;
	int		len_filename;

	splitted_textures = ft_split(textures[1], '/');
	len_textures = ft_strlen_double_tab(splitted_textures) - 1;
	len_filename = ft_strlen(splitted_textures[len_textures]);
	if (!ft_strcmp(textures[0], "NO") || !ft_strcmp(textures[0], "SO")
		|| !ft_strcmp(textures[0], "WE") || !ft_strcmp(textures[0], "EA"))
	{
		if (check_file_name(textures[1], ".xpm") == false || len_filename == 4)
		{
			free_double_tab(splitted_textures);
			return (1);
		}
	}
	free_double_tab(splitted_textures);
	return (0);
}

int	assign_line_to_elem(t_texture_color_data *texture_color_data,
	char *line, int *i)
{
	char	**splitted_line;

	if (!line[0])
		return (-1);
	splitted_line = ft_split(line, ' ');
	free(line);
	if (ft_strlen_double_tab(splitted_line) != 2 || check_ext(splitted_line))
	{
		free_double_tab(splitted_line);
		return (-1);
	}
	fill_texture_elements(texture_color_data, splitted_line);
	if (ft_strcmp(splitted_line[0], "C") == 0)
	{
		if (get_color_elements(texture_color_data, splitted_line, 1) == -1)
			return (-1);
	}
	if (ft_strcmp(splitted_line[0], "F") == 0)
	{
		if (get_color_elements(texture_color_data, splitted_line, 0) == -1)
			return (-1);
	}
	free_double_tab(splitted_line);
	(*i)++;
	return (0);
}

int	skip_textures_and_colors(char *scene_file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(scene_file, O_RDONLY);
	i = 0;
	if (fd == -1)
		return (-1);
	while (i < 6)
	{
		line = get_next_line(fd, 1);
		if (ft_strcmp(line, "\n") != 0)
		{
			free(line);
			i++;
		}
		else
			free(line);
	}
	return (fd);
}

char	*trim_end_of_line(int fd)
{
	char	*line;
	char	*trim_line;

	line = get_next_line(fd, 1);
	if (!line)
	{
		ft_print_error("Error\nCheck scene file\n");
		close(fd);
		return (NULL);
	}
	trim_line = ft_strtrim(line, "\n");
	if (!trim_line)
	{
		ft_print_error("Error\nCheck scene file\n");
		close(fd);
		return (NULL);
	}
	free(line);
	return (trim_line);
}

int	init_textures_and_colors(t_texture_color_data *texture_color_data,
		char *scene_file)
{
	int		fd;
	int		i;
	char	*trim_line;

	i = 0;
	fd = open(scene_file, O_RDONLY);
	if (fd == -1)
		ft_print_error("Error\nOpen failed\n");
	while (i < 6 && fd != -1)
	{
		trim_line = trim_end_of_line(fd);
		if (!trim_line)
			return (-1);
		if (!trim_line[0])
			free(trim_line);
		else if (assign_line_to_elem(texture_color_data, trim_line, &i) == -1)
		{
			close(fd);
			ft_print_error("Error\nCheck scene file\n");
			return (-2);
		}
	}
	return (fd);
}
