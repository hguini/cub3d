/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 03:53:29 by hguini            #+#    #+#             */
/*   Updated: 2021/03/22 17:17:38 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor(t_map *map)
{
	map->z = map->drawend;
	while (map->z < map->r_y)
	{
		my_mlx_pixel_put(&map->img_win, map->x, map->z,\
		threatment_color(map->f_r, map->f_g, map->f_b));
		map->z++;
	}
}

void	draw_ceiling(t_map *map)
{
	if (map->y < map->drawstart)
		my_mlx_pixel_put(&map->img_win, map->x, map->y,\
		threatment_color(map->c_r, map->c_g, map->c_b));
}

void	draw_tex_second(t_map *map)
{
	unsigned int color;

	map->tex_y = (int)map->texpos;
	map->texpos += map->step;
	if (map->step_y > 0)
	{
		color = my_mlx_pixel_take(&map->west_texture, map->tex_x, map->tex_y);
		my_mlx_pixel_put(&map->img_win, map->x, map->y, color);
	}
	else if (map->step_y < 0)
	{
		color = my_mlx_pixel_take(&map->east_texture, map->tex_x, map->tex_y);
		my_mlx_pixel_put(&map->img_win, map->x, map->y, color);
	}
}

void	draw_tex_first(t_map *map)
{
	unsigned int color;

	map->tex_y = (int)map->texpos;
	map->texpos += map->step;
	if (map->step_x > 0)
	{
		color = my_mlx_pixel_take(&map->north_texture, map->tex_x, map->tex_y);
		my_mlx_pixel_put(&map->img_win, map->x, map->y, color);
	}
	else if (map->step_x < 0)
	{
		color = my_mlx_pixel_take(&map->south_texture, map->tex_x, map->tex_y);
		my_mlx_pixel_put(&map->img_win, map->x, map->y, color);
	}
}

void	draw_map(t_map *map)
{
	double zbuffer[map->r_x];

	map->x = 0;
	while (map->x < map->r_x)
	{
		map_assign(map);
		map->y = 0;
		while (map->y < map->drawend)
		{
			draw_ceiling(map);
			if (map->y >= map->drawstart && map->y <= map->drawend)
			{
				if (map->side == 0)
					draw_tex_first(map);
				if (map->side == 1)
					draw_tex_second(map);
			}
			map->y++;
		}
		draw_floor(map);
		zbuffer[map->x] = map->perpwalldist;
		map->x++;
	}
	sprite(map, zbuffer);
}
