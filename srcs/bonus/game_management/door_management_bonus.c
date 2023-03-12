/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_management_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:55:10 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:55:12 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

static char	**update_mat(char **mat, int x, int y, t_player player)
{
	int	x_mat;
	int	y_mat;

	x_mat = player.pxl_x / SQ_SIZE;
	y_mat = player.pxl_y / SQ_SIZE;
	if (x)
	{
		if (mat[y_mat][x] == '2')
			mat[y_mat][x] = '3';
		else if (mat[y_mat][x] == '3')
			mat[y_mat][x] = '2';
	}
	if (y)
	{
		if (mat[y][x_mat] == '2')
			mat[y][x_mat] = '3';
		else if (mat[y][x_mat] == '3')
			mat[y][x_mat] = '2';
	}
	return (mat);
}

int	door_management(t_all *game_struct)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (game_struct->player.angle > M_PI / 4
		&& game_struct->player.angle < 3 * M_PI / 4)
		y = game_struct->player.pxl_y / SQ_SIZE - 1;
	else if (game_struct->player.angle > 3 * M_PI / 4
		&& game_struct->player.angle < 5 * M_PI / 4)
		x = game_struct->player.pxl_x / SQ_SIZE - 1;
	else if (game_struct->player.angle > 5 * M_PI / 4
		&& game_struct->player.angle < 7 * M_PI / 4)
		y = game_struct->player.pxl_y / SQ_SIZE + 1;
	else if (game_struct->player.angle > 7 * M_PI / 4
		|| game_struct->player.angle < M_PI / 4)
		x = game_struct->player.pxl_x / SQ_SIZE + 1;
	if (x || y)
		game_struct->mat = update_mat(game_struct->mat, x, y,
				game_struct->player);
	return (0);
}
