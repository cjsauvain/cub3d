/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:14:15 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 16:03:49 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

typedef struct s_texture_color_data
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*door_texture;
	char	*s_one_sprite;
	char	*s_two_sprite;
	char	*s_three_sprite;
	char	*s_four_sprite;
	char	*s_five_sprite;
	char	*s_six_sprite;
	char	*s_seven_sprite;
	int		c_color[3];
	int		f_color[3];
}				t_texture_color_data;

typedef struct s_no_tex
{
	void	*no_image;
	int		width;
	int		height;
}				t_no_tex;

typedef struct s_so_tex
{
	void	*so_image;
	int		width;
	int		height;
}				t_so_tex;

typedef struct s_we_tex
{
	void	*we_image;
	int		width;
	int		height;
}				t_we_tex;

typedef struct s_ea_tex
{
	void	*ea_image;
	int		width;
	int		height;
}				t_ea_tex;

typedef struct s_render_data
{
	int			wall_side;
	int			door_wall;
	float		ray_hit_x;
	int			tex_x;
	t_no_tex	no_tex;
	t_so_tex	so_tex;
	t_we_tex	we_tex;
	t_ea_tex	ea_tex;
	void		*door_image;
	int			door_width;
	int			door_height;
	void		*s_one_image;
	void		*s_two_image;
	void		*s_three_image;
	void		*s_four_image;
	void		*s_five_image;
	void		*s_six_image;
	void		*s_seven_image;
	int			c_color;
	int			f_color;
}				t_render_data;

typedef struct s_window
{
	void	*win_ptr;
	void	*mlx;	
}				t_window;

typedef struct s_wall_coords
{
	float	x;
	float	y;
}				t_wall_coords;

typedef struct s_triangle
{
	int	x_a;
	int	y_a;
	int	x_b;
	int	y_b;
	int	x_c;
	int	y_c;
}				t_triangle;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}				t_img_data;

typedef struct s_map_data
{
	int	map_width;
	int	map_height;
	int	nb_players;
}				t_map_data;

typedef struct s_player
{
	float	pxl_x;
	float	pxl_y;
	float	angle;
}				t_player;

typedef struct s_raycast_dist
{
	float	side_x;
	float	side_y;
	float	delta_x;
	float	delta_y;
	int		step_x;
	int		step_y;
	int		side;
}				t_raycast_dist;

typedef struct s_raycast_dir
{
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	camera_x;
	float	raydir_x;
	float	raydir_y;
}				t_raycast_dir;

typedef struct s_render_images
{
	t_img_data	minimap_render;
	t_img_data	window_render;
}				t_render_images;

typedef struct s_all
{
	t_texture_color_data	texture_color_data;
	t_render_data			render_data;
	t_render_images			render_images;
	t_window				window;
	t_map_data				map_data;
	t_player				player;
	t_raycast_dir			direction;
	t_raycast_dist			distance;
	char					**mat;
}				t_all;

#endif
