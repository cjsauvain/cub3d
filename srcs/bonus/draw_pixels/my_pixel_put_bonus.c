/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:54:44 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:54:46 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

void	my_pixel_put(t_img_data *data, float x, float y, int color)
{
	char	*dst;

	dst = data->addr + ((int)y * data->line_length + (int)x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_img_data	draw_border(t_img_data img)
{
	int	i;

	i = 0;
	while (i <= MINI_WIDTH + 1)
	{
		my_pixel_put(&img, i, 0, BORDER_COLOR);
		my_pixel_put(&img, i, MINI_HEIGHT, BORDER_COLOR);
		i++;
	}
	i = 0;
	while (i <= MINI_HEIGHT + 1)
	{
		my_pixel_put(&img, 0, i, BORDER_COLOR);
		my_pixel_put(&img, MINI_WIDTH, i, BORDER_COLOR);
		i++;
	}
	return (img);
}
