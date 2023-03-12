/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:58:16 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:58:17 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

static float	get_angle(char c)
{
	if (c == 'N')
		return (M_PI / 2);
	else if (c == 'S')
		return (3 * M_PI / 2);
	if (c == 'W')
		return (M_PI);
	return (0);
}

static t_player	init(t_player pos, int i, int j, char c)
{
	pos.pxl_x = j * SQ_SIZE + (SQ_SIZE / 2);
	pos.pxl_y = i * SQ_SIZE + (SQ_SIZE / 2);
	pos.angle = get_angle(c);
	return (pos);
}

static t_player	init_player_position(t_player player, char **mat)
{
	int	i;
	int	j;
	int	trigger;

	i = 1;
	trigger = 0;
	while (!trigger)
	{
		j = 1;
		while (mat[i][j] && !trigger)
		{
			if (mat[i][j] == 'W' || mat[i][j] == 'E'
				|| mat[i][j] == 'N' || mat[i][j] == 'S')
			{
				player = init(player, i, j, mat[i][j]);
				trigger++;
			}
			j++;
		}
		i++;
	}
	return (player);
}

void	init_data(t_all *game_struct)
{
	game_struct->player = init_player_position(game_struct->player,
			game_struct->mat);
	game_struct->direction = init_raycast_dir(game_struct);
}
