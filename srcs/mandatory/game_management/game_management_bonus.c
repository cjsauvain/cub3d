/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:48:44 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:48:47 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	game_management(int keycode, t_all *game_struct)
{
	if (keycode == XK_Escape)
		destroy(game_struct);
	else
		movement_management(keycode, game_struct);
	return (0);
}
