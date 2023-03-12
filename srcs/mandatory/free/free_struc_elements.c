/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struc_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:48:20 by blevrel           #+#    #+#             */
/*   Updated: 2023/02/27 15:48:22 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

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
}
