/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raycast_dist_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:58:01 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:58:04 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

static t_raycast_dist	get_first_delta_dist(float raydir_x, float raydir_y)
{
	t_raycast_dist	distance;

	distance.delta_x = fabs(1 / raydir_x);
	if (!raydir_x)
		distance.delta_x = pow(10, 30);
	distance.delta_y = fabs(1 / raydir_y);
	if (!raydir_y)
		distance.delta_y = pow(10, 30);
	return (distance);
}

static t_raycast_dist	get_first_side_dist(float pxl_x, float pxl_y,
	t_raycast_dist distance, t_raycast_dir direction)
{
	if (direction.raydir_x < 0)
	{
		distance.side_x = ((pxl_x / SQ_SIZE) - floor(pxl_x / SQ_SIZE))
			* distance.delta_x;
		distance.step_x = -1;
	}
	else
	{
		distance.side_x = (floor(pxl_x / SQ_SIZE) + 1 - (pxl_x / SQ_SIZE))
			* distance.delta_x;
		distance.step_x = 1;
	}
	if (direction.raydir_y < 0)
	{
		distance.side_y = ((pxl_y / SQ_SIZE) - floor(pxl_y / SQ_SIZE))
			* distance.delta_y;
		distance.step_y = -1;
	}
	else
	{
		distance.side_y = (floor(pxl_y / SQ_SIZE) + 1 - (pxl_y / SQ_SIZE))
			* distance.delta_y;
		distance.step_y = 1;
	}
	return (distance);
}

t_raycast_dist	get_raycast_dist(t_raycast_dir direction, t_player player)
{
	t_raycast_dist	distance;

	distance = get_first_delta_dist(direction.raydir_x, direction.raydir_y);
	distance = get_first_side_dist(player.pxl_x, player.pxl_y,
			distance, direction);
	return (distance);
}
