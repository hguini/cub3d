/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_texture_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 03:34:57 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 06:38:58 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	threatment_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void			filling_texture_img_sec(t_map *map)
{
	void		*img;

	if (!(img = mlx_xpm_file_to_image(map->mlx, map->ea,\
	&map->east_texture.width, &map->east_texture.height)))
		check_valid('T');
	else
		map->east_texture.addr = mlx_get_data_addr(img,\
		&map->east_texture.bits_per_pixel, &map->east_texture.line_length,\
		&map->east_texture.endian);
	if (!(img = mlx_xpm_file_to_image(map->mlx, map->s,\
	&map->sprite_texture.width, &map->sprite_texture.height)))
		check_valid('T');
	else
		map->sprite_texture.addr = mlx_get_data_addr(img,\
		&map->sprite_texture.bits_per_pixel, &map->sprite_texture.line_length,\
		&map->sprite_texture.endian);
}

void			filling_texture_img(t_map *map)
{
	void		*img;

	if (!(img = mlx_xpm_file_to_image(map->mlx, map->no,\
	&map->north_texture.width, &map->north_texture.height)))
		check_valid('T');
	else
		map->north_texture.addr = mlx_get_data_addr(img,\
		&map->north_texture.bits_per_pixel, &map->north_texture.line_length,\
		&map->north_texture.endian);
	if (!(img = mlx_xpm_file_to_image(map->mlx, map->so,\
	&map->south_texture.width, &map->south_texture.height)))
		check_valid('T');
	else
		map->south_texture.addr = mlx_get_data_addr(img,\
		&map->south_texture.bits_per_pixel, &map->south_texture.line_length,\
		&map->south_texture.endian);
	if (!(img = mlx_xpm_file_to_image(map->mlx, map->we,\
	&map->west_texture.width, &map->west_texture.height)))
		check_valid('T');
	else
		map->west_texture.addr = mlx_get_data_addr(img,\
		&map->west_texture.bits_per_pixel, &map->west_texture.line_length,\
		&map->west_texture.endian);
	filling_texture_img_sec(map);
}
