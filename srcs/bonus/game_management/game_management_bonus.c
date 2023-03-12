/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:55:49 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:55:52 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

int	game_management(int keycode, t_all *game_struct)
{
	if (keycode == 'e')
		door_management(game_struct);
	else if (keycode == XK_Escape)
		destroy(game_struct);
	else
		movement_management(keycode, game_struct);
	return (0);
}
