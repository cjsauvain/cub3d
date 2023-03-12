/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struc_elements_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:54:55 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:54:57 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

void	free_struc_elements(t_texture_color_data texture_color_data)
{
	if (texture_color_data.no_texture)
		free(texture_color_data.no_texture);
	if (texture_color_data.so_texture)
		free(texture_color_data.so_texture);
	if (texture_color_data.we_texture)
		free(texture_color_data.we_texture);
	if (texture_color_data.ea_texture)
		free(texture_color_data.ea_texture);
	if (texture_color_data.door_texture)
		free(texture_color_data.door_texture);
	if (texture_color_data.s_one_sprite)
		free(texture_color_data.s_one_sprite);
	if (texture_color_data.s_two_sprite)
		free(texture_color_data.s_two_sprite);
	if (texture_color_data.s_three_sprite)
		free(texture_color_data.s_three_sprite);
	if (texture_color_data.s_four_sprite)
		free(texture_color_data.s_four_sprite);
	if (texture_color_data.s_five_sprite)
		free(texture_color_data.s_five_sprite);
	if (texture_color_data.s_six_sprite)
		free(texture_color_data.s_six_sprite);
	if (texture_color_data.s_seven_sprite)
		free(texture_color_data.s_seven_sprite);
}
