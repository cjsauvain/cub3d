/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:49:21 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:49:23 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all	game_struc;

	if (argc != 2)
	{
		ft_print_error("Invalid args. Usage: %s *scene_file*.cub\n", argv[0]);
		return (-1);
	}
	init_struc(&game_struc);
	game_struc.mat = start_parsing(argv[1], &game_struc);
	if (!game_struc.mat)
		return (-2);
	game_struc.window.mlx = mlx_init();
	if (!load_textures(game_struc.texture_color_data, &game_struc.render_data,
			game_struc.window))
		destroy_tex_not_found(&game_struc);
	game_struc.window.win_ptr = mlx_new_window(game_struc.window.mlx, WIN_WIDTH,
			WIN_HEIGHT, "cub3D");
	init_images(&game_struc.render_images, game_struc.window);
	launch_game(&game_struc);
	mlx_loop(game_struc.window.mlx);
	return (0);
}
