/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:54:22 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:54:24 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

int	pick_pixel_color(char **mat, int x_pxl, int y_pxl, t_map_data map_data)
{
	int	x_pos_in_mat;
	int	y_pos_in_mat;

	x_pos_in_mat = x_pxl / SQ_SIZE;
	y_pos_in_mat = y_pxl / SQ_SIZE;
	if ((x_pos_in_mat <= 0 || x_pos_in_mat >= map_data.map_width)
		|| (y_pos_in_mat <= 0 || y_pos_in_mat >= map_data.map_height)
		|| mat[y_pos_in_mat][x_pos_in_mat] == '1'
		|| mat[y_pos_in_mat][x_pos_in_mat] == 2
		|| ft_isspace(mat[y_pos_in_mat][x_pos_in_mat]))
		return (WALL_COLOR);
	else if (mat[y_pos_in_mat][x_pos_in_mat] == '3')
		return (O_DOOR_COLOR);
	else if (mat[y_pos_in_mat][x_pos_in_mat] == '2')
		return (C_DOOR_COLOR);
	else
		return (FLOOR_COLOR);
}

t_img_data	put_minimap_pixel(t_img_data img, int color)
{
	static int	img_x = 1;
	static int	img_y = 1;

	my_pixel_put(&img, img_x, img_y, color);
	img_x++;
	if (img_x == MINI_WIDTH)
	{
		img_y++;
		img_x = 1;
	}
	if (img_y == MINI_HEIGHT)
		img_y = 1;
	return (img);
}

t_img_data	draw_player(t_img_data img, t_triangle tri)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;

	max_x = ft_max(tri.x_a, ft_max(tri.x_b, tri.x_c));
	max_y = ft_max(tri.y_a, ft_max(tri.y_b, tri.y_c));
	x = ft_min(tri.x_a, ft_min(tri.x_b, tri.x_c));
	while (x <= max_x)
	{
		y = ft_min(tri.y_a, ft_min(tri.y_b, tri.y_c));
		while (y <= max_y)
		{
			if ((tri.y_b - tri.y_c) * x + (tri.x_c - tri.x_b) * y + tri.x_b
				* tri.y_c - tri.x_c * tri.y_b >= 0 && (tri.y_c - tri.y_a)
				* x + (tri.x_a - tri.x_c) * y + tri.x_c * tri.y_a - tri.x_a
				* tri.y_c >= 0 && (tri.y_a - tri.y_b) * x + (tri.x_b - tri.x_a)
				* y + tri.x_a * tri.y_b - tri.x_b * tri.y_a >= 0)
				my_pixel_put(&img, x, y, PLAYER_COLOR);
			y++;
		}
		x++;
	}
	return (img);
}

t_img_data	fill_minimap(t_img_data img, char **mat, t_player player,
	t_map_data map_data)
{
	float	y_check;
	float	x_check;
	float	x_pxl_limit;
	float	y_pxl_limit;
	int		color;

	x_pxl_limit = player.pxl_x + ((float)MINI_VISION * (float)SQ_SIZE);
	y_pxl_limit = player.pxl_y + ((float)MINI_VISION * (float)SQ_SIZE);
	y_check = player.pxl_y - ((float)MINI_VISION * (float)SQ_SIZE);
	while (y_check < y_pxl_limit)
	{
		x_check = player.pxl_x - ((float)MINI_VISION * (float)SQ_SIZE);
		while (x_check < x_pxl_limit)
		{
			color = pick_pixel_color(mat, x_check, y_check, map_data);
			img = put_minimap_pixel(img, color);
			x_check++;
		}
		y_check++;
	}
	return (img);
}

void	display_minimap(t_all game_struct)
{
	t_triangle	player_triangle;

	player_triangle = get_triangle_coords(game_struct.player.angle);
	draw_border(game_struct.render_images.minimap_render);
	fill_minimap(game_struct.render_images.minimap_render,
		game_struct.mat, game_struct.player, game_struct.map_data);
	draw_player(game_struct.render_images.minimap_render, player_triangle);
	mlx_put_image_to_window(game_struct.window.mlx,
		game_struct.window.win_ptr,
		game_struct.render_images.minimap_render.img, MINI_POS, MINI_POS);
}
