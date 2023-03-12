/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:56:05 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:56:07 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

static t_player	go_up(t_player pos, char **mat)
{
	if (!check_collision_x(pos, mat, "+cos"))
		pos.pxl_x += (cos(pos.angle) * MOVESPEED);
	if (!check_collision_y(pos, mat, "-sin"))
		pos.pxl_y -= (sin(pos.angle) * MOVESPEED);
	return (pos);
}

static t_player	go_down(t_player pos, char **mat)
{
	if (!check_collision_x(pos, mat, "-cos"))
		pos.pxl_x -= (cos(pos.angle) * MOVESPEED);
	if (!check_collision_y(pos, mat, "+sin"))
		pos.pxl_y += (sin(pos.angle) * MOVESPEED);
	return (pos);
}

static t_player	go_left(t_player pos, char **mat)
{
	if (!check_collision_x(pos, mat, "-sin"))
		pos.pxl_x -= (sin(pos.angle) * MOVESPEED);
	if (!check_collision_y(pos, mat, "-cos"))
		pos.pxl_y -= (cos(pos.angle) * MOVESPEED);
	return (pos);
}

static t_player	go_right(t_player pos, char **mat)
{
	if (!check_collision_x(pos, mat, "+sin"))
		pos.pxl_x += (sin(pos.angle) * MOVESPEED);
	if (!check_collision_y(pos, mat, "+cos"))
		pos.pxl_y += (cos(pos.angle) * MOVESPEED);
	return (pos);
}

t_player	move(int keycode, t_player pos, char **mat)
{
	if (keycode == 'w')
		pos = go_up(pos, mat);
	else if (keycode == 's')
		pos = go_down(pos, mat);
	else if (keycode == 'a')
		pos = go_left(pos, mat);
	else if (keycode == 'd')
		pos = go_right(pos, mat);
	return (pos);
}
