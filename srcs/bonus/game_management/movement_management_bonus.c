/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_management_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:55:29 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:55:31 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

static float	go_left_or_right(int keycode, float angle)
{
	if (keycode == XK_Left)
	{
		angle += (KEY_ROTSPEED * M_PI / 180);
		if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
	}
	else if (keycode == XK_Right)
	{
		angle -= (KEY_ROTSPEED * M_PI / 180);
		if (angle < 0)
			angle += 2 * M_PI;
	}
	return (angle);
}

int	movement_management(int keycode, t_all *game_struct)
{
	if (keycode == XK_Left || keycode == XK_Right)
	{
		game_struct->player.angle = go_left_or_right(keycode,
				game_struct->player.angle);
		game_struct->direction = get_new_dir_and_plane(game_struct->direction,
				game_struct->player.angle);
	}
	else if (keycode == 'w' || keycode == 's'
		|| keycode == 'a' || keycode == 'd')
		game_struct->player = move(keycode, game_struct->player,
				game_struct->mat);
	return (0);
}
