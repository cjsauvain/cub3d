/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_coordinates.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:47:52 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:47:55 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

t_triangle	get_triangle_coords(float angle_a)
{
	t_triangle	player_triangle;
	float		angle_b;
	float		angle_c;

	angle_a = -angle_a;
	angle_b = angle_a + M_PI * 2 / 3;
	angle_c = angle_a + M_PI * 4 / 3;
	player_triangle.x_a = (MINI_WIDTH / 2) + (MINI_PLAYER_SIZE * 1.3)
		* cos(angle_a);
	player_triangle.y_a = (MINI_HEIGHT / 2) + (MINI_PLAYER_SIZE * 1.3)
		* sin(angle_a);
	player_triangle.x_b = (MINI_WIDTH / 2) + MINI_PLAYER_SIZE
		* cos(angle_b);
	player_triangle.y_b = (MINI_HEIGHT / 2) + MINI_PLAYER_SIZE
		* sin(angle_b);
	player_triangle.x_c = (MINI_WIDTH / 2) + MINI_PLAYER_SIZE
		* cos(angle_c);
	player_triangle.y_c = (MINI_HEIGHT / 2) + MINI_PLAYER_SIZE
		* sin(angle_c);
	return (player_triangle);
}
