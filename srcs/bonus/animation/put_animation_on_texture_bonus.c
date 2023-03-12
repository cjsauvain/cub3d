/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_animation_on_texture_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:53:56 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:53:58 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

static int	get_index_sprite(void)
{
	static int		current_sprite_index = 1;
	static long int	last_sprite_switch_time = 0;
	struct timeval	current_time;
	long int		time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_usec / 1000 + current_time.tv_sec * 1000;
	if (time - last_sprite_switch_time > SWITCH_TIME_SPRITE)
	{
		last_sprite_switch_time = time;
		current_sprite_index = (current_sprite_index + 1) % 7;
	}
	return (current_sprite_index);
}

static void	*select_sprite(t_render_data render_data)
{
	int	current_sprite_index;

	current_sprite_index = get_index_sprite();
	if (current_sprite_index == 1)
		return (render_data.s_one_image);
	else if (current_sprite_index == 2)
		return (render_data.s_two_image);
	else if (current_sprite_index == 3)
		return (render_data.s_three_image);
	else if (current_sprite_index == 4)
		return (render_data.s_four_image);
	else if (current_sprite_index == 5)
		return (render_data.s_five_image);
	else if (current_sprite_index == 6)
		return (render_data.s_six_image);
	return (render_data.s_seven_image);
}

static int	get_texture_color(t_render_data render_data, int y, int x)
{
	t_img_data	image;
	int			i;
	int			color;

	color = 0;
	image.img = select_sprite(render_data);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	i = ((x * SPRITE_WIDTH) + y) * 4;
	color = color | (unsigned char)(image.addr[i + 2]);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i + 1]);
	color = color << 8;
	color = color | (unsigned char)(image.addr[i]);
	return (color);
}

void	put_animation_on_texture(float distance, int pxl_horizontal,
t_img_data render_img, t_render_data render_data)
{
	int		wall_height;
	int		pxl_vertical;
	int		pxl_sky_and_floor;
	int		color;
	double	ratio;

	wall_height = WIN_HEIGHT / distance;
	ratio = (double)SPRITE_WIDTH / (double)wall_height;
	pxl_sky_and_floor = (WIN_HEIGHT - wall_height) / 2;
	pxl_vertical = 0;
	while (pxl_vertical < WIN_HEIGHT)
	{
		if (pxl_vertical > pxl_sky_and_floor && pxl_vertical
			< pxl_sky_and_floor + wall_height)
		{
			color = get_texture_color(render_data,
					(pxl_vertical - pxl_sky_and_floor)
					* ratio, render_data.tex_x);
			if (color != 0x000000)
				my_pixel_put(&render_img, pxl_horizontal, pxl_vertical, color);
		}
		pxl_vertical++;
	}
}
