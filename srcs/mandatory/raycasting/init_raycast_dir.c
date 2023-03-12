/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:51:01 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:51:03 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static t_raycast_dir	get_plane(char c)
{
	t_raycast_dir	direction;

	direction.plane_x = (float)PLANE;
	direction.plane_y = 0;
	if (c == 'S')
	{
		direction.plane_x = ((float)-PLANE);
		direction.plane_y = 0;
	}
	else if (c == 'W')
	{
		direction.plane_x = 0;
		direction.plane_y = ((float)-PLANE);
	}
	else if (c == 'E')
	{
		direction.plane_x = 0;
		direction.plane_y = (float)PLANE;
	}
	return (direction);
}

static t_raycast_dir	get_dir(t_raycast_dir direction, char c)
{
	direction.dir_x = 0;
	direction.dir_y = -1;
	if (c == 'S')
	{
		direction.dir_x = 0;
		direction.dir_y = 1;
	}
	else if (c == 'W')
	{
		direction.dir_x = -1;
		direction.dir_y = 0;
	}
	else if (c == 'E')
	{
		direction.dir_x = 1;
		direction.dir_y = 0;
	}
	return (direction);
}

static t_raycast_dir	init(char c)
{
	t_raycast_dir	direction;

	direction = get_plane(c);
	direction = get_dir(direction, c);
	return (direction);
}

t_raycast_dir	init_raycast_dir(t_all *game_struct)
{
	t_raycast_dir	direction;
	int				i;
	int				j;
	int				trigger;

	i = 1;
	trigger = 0;
	while (!trigger)
	{
		j = 1;
		while (game_struct->mat[i][j] && !trigger)
		{
			if (game_struct->mat[i][j] == 'W' || game_struct->mat[i][j] == 'E'
				|| game_struct->mat[i][j] == 'N'
				|| game_struct->mat[i][j] == 'S')
			{
				direction = init(game_struct->mat[i][j]);
				trigger++;
			}
			j++;
		}
		i++;
	}
	return (direction);
}
