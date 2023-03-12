/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:50:23 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/28 16:26:00 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	fill_color_elements(char **col_value,
	t_texture_color_data *texture_color_data, int trigger)
{
	int	i;
	int	res;

	i = 0;
	while (i < 3)
	{
		res = ft_atoi(col_value[i]);
		if (res < 0 || res > 255)
			return (-1);
		if (trigger == 1)
			texture_color_data->c_color[i] = res;
		if (trigger == 0)
			texture_color_data->f_color[i] = res;
		i++;
	}
	return (0);
}

static int	check_line_format(char **line)
{
	size_t	i;

	i = 0;
	if (line[1][0] == ',')
		return (1);
	while (line[1][i])
	{
		if (!ft_isdigit(line[1][i]) && line[1][i] != ',')
			return (1);
		if (line[1][i] == ',' && i == ft_strlen(line[1]) - 1)
			return (1);
		i++;
	}
	return (0);
}

static int	check_multiple_comas(char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] == ',' && line[i][j + 1] == ',')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_color_elements(t_texture_color_data *texture_color_data,
	char **line, int trigger)
{
	char	**color_value;

	color_value = ft_split(line[1], ',');
	if (color_value == NULL)
		return (-1);
	if (ft_strlen_double_tab(color_value) != 3
		|| check_line_format(line) || check_multiple_comas(line))
	{
		free_double_tab(color_value);
		free_double_tab(line);
		return (-1);
	}
	if (fill_color_elements(color_value, texture_color_data, trigger) == -1)
	{
		free_double_tab(color_value);
		free_double_tab(line);
		return (-1);
	}
	free_double_tab(color_value);
	return (0);
}

void	fill_texture_elements(t_texture_color_data *texture_color_data,
		char **line)
{
	if (ft_strcmp(line[0], "NO") == 0 && !texture_color_data->no_texture)
		texture_color_data->no_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "SO") == 0 && !texture_color_data->so_texture)
		texture_color_data->so_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "WE") == 0 && !texture_color_data->we_texture)
		texture_color_data->we_texture = ft_strdup(line[1]);
	if (ft_strcmp(line[0], "EA") == 0 && !texture_color_data->ea_texture)
		texture_color_data->ea_texture = ft_strdup(line[1]);
}
