/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hit_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:54:15 by blevrel           #+#    #+#             */
/*   Updated: 2023/03/07 11:26:08 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

void	get_side_of_wall_hit(t_render_data *render_data,
				t_raycast_dist distance, t_raycast_dir direction)
{
	float	angle;

	angle = atan2(direction.raydir_y, direction.raydir_x);
	if (distance.side == 1 && angle < 0)
		render_data->wall_side = SOUTH;
	else if (distance.side == 1 && angle > 0)
		render_data->wall_side = NORTH;
	else if (distance.side == 0 && (angle > M_PI / 2 || angle < -M_PI / 2))
		render_data->wall_side = EAST;
	else
		render_data->wall_side = WEST;
}

float	get_ray_hit_coords(t_raycast_dist distance, t_player player,
			float perp_wall_dist, t_raycast_dir direction)
{
	float			x;

	if (distance.side == 0)
		x = player.pxl_y / SQ_SIZE + perp_wall_dist * direction.raydir_y;
	if (distance.side == 1)
		x = player.pxl_x / SQ_SIZE + perp_wall_dist * direction.raydir_x;
	x -= floor(x);
	return (x);
}
