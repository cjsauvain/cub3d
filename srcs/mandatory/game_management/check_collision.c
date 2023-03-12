/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:48:32 by blevrel           #+#    #+#             */
/*   Updated: 2023/03/07 14:34:37 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static int	get_new_x_in_mat(float pxl_x, float angle, char *oper)
{
	float	new_x;

	new_x = pxl_x;
	if (!ft_strcmp(oper, "+cos"))
		new_x += cos(angle) * MOVESPEED;
	else if (!ft_strcmp(oper, "-cos"))
		new_x -= cos(angle) * MOVESPEED;
	else if (!ft_strcmp(oper, "-sin"))
		new_x -= sin(angle) * MOVESPEED;
	else if (!ft_strcmp(oper, "+sin"))
		new_x += sin(angle) * MOVESPEED;
	if (pxl_x - new_x > 0)
		return ((new_x - 1) / SQ_SIZE);
	return (new_x / SQ_SIZE);
}

static int	get_new_y_in_mat(float pxl_y, float angle, char *oper)
{
	float	new_y;

	new_y = pxl_y;
	if (!ft_strcmp(oper, "-sin"))
		new_y -= sin(angle) * MOVESPEED;
	else if (!ft_strcmp(oper, "+sin"))
		new_y += sin(angle) * MOVESPEED;
	else if (!ft_strcmp(oper, "-cos"))
		new_y -= cos(angle) * MOVESPEED;
	else if (!ft_strcmp(oper, "+cos"))
		new_y += cos(angle) * MOVESPEED;
	if (pxl_y - new_y > 0)
		return ((new_y - 1) / SQ_SIZE);
	return (new_y / SQ_SIZE);
}

int	check_collision_x(t_player pos, char **mat, char *oper)
{
	int	new_x;
	int	old_y;

	new_x = get_new_x_in_mat(pos.pxl_x, pos.angle, oper);
	old_y = pos.pxl_y / 32;
	if (mat[old_y][new_x] == '1')
		return (1);
	return (0);
}

int	check_collision_y(t_player pos, char **mat, char *oper)
{
	int	new_y;
	int	old_x;

	new_y = get_new_y_in_mat(pos.pxl_y, pos.angle, oper);
	old_x = pos.pxl_x / 32;
	if (mat[new_y][old_x] == '1')
		return (1);
	return (0);
}
