/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:49:10 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:49:13 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static float	go_left_or_right(int keycode, float angle)
{
	if (keycode == XK_Left)
	{
		angle += (ROT_SPEED * M_PI / 180);
		if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
	}
	else if (keycode == XK_Right)
	{
		angle -= (ROT_SPEED * M_PI / 180);
		if (angle < 0)
			angle += 2 * M_PI;
	}
	return (angle);
}

static t_raycast_dir	get_new_dir_and_plane(t_raycast_dir direction,
	float angle)
{
	direction.dir_x = cos(angle);
	direction.dir_y = -sin(angle);
	direction.plane_x = PLANE * sin(angle);
	direction.plane_y = PLANE * cos(angle);
	return (direction);
}

int	movement_management(int keycode, t_all *game_struct)
{
	if (keycode == XK_Left || keycode == XK_Right)
	{
		game_struct->player.angle = go_left_or_right(keycode,
				game_struct->player.angle);
		game_struct->direction = get_new_dir_and_plane(game_struct->direction,
				game_struct->player.angle);
		cast_rays(game_struct);
		display_minimap(*game_struct);
	}
	else if (keycode == 'w' || keycode == 's'
		|| keycode == 'a' || keycode == 'd')
	{
		game_struct->player = move(keycode, game_struct->player,
				game_struct->mat);
		cast_rays(game_struct);
		display_minimap(*game_struct);
	}
	return (0);
}
