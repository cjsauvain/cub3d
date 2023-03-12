/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:33:48 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:56:25 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	redisplay_map(int x, int y, t_all *game_struct)
{
	(void)y;
	if (x > WIN_WIDTH / 2)
	{
		game_struct->player.angle -= (MOUSE_ROTSPEED * M_PI / 180);
		if (game_struct->player.angle < 0)
			game_struct->player.angle += 2 * M_PI;
		game_struct->direction = get_new_dir_and_plane(game_struct->direction,
				game_struct->player.angle);
		mlx_mouse_move(game_struct->window.mlx, game_struct->window.win_ptr,
			WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	else if (x < WIN_WIDTH / 2)
	{
		game_struct->player.angle += (MOUSE_ROTSPEED * M_PI / 180);
		if (game_struct->player.angle > 2 * M_PI)
			game_struct->player.angle -= 2 * M_PI;
		game_struct->direction = get_new_dir_and_plane(game_struct->direction,
				game_struct->player.angle);
		mlx_mouse_move(game_struct->window.mlx, game_struct->window.win_ptr,
			WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	return (0);
}

static int	display(t_all *game_struct)
{
	cast_rays(game_struct);
	display_minimap(*game_struct);
	return (0);
}

void	launch_game(t_all *game_struct)
{
	init_data(game_struct);
	mlx_hook(game_struct->window.win_ptr, KeyPress, KeyPressMask,
		game_management, game_struct);
	mlx_hook(game_struct->window.win_ptr, DestroyNotify, StructureNotifyMask,
		destroy, game_struct);
	mlx_hook(game_struct->window.win_ptr, MotionNotify, PointerMotionMask,
		redisplay_map, game_struct);
	mlx_loop_hook(game_struct->window.mlx, display, game_struct);
}
