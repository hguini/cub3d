/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:15:35 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 02:52:47 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				draw_sprite(t_map *map)
{
	int				y;
	int				d;
	unsigned int	color;

	y = map->spr.draw_start_y;
	while (y < map->spr.draw_end_y)
	{
		d = y * 256 - map->r_y * 128 + map->spr.sprite_height * 128;
		map->spr.tex_y = ((d * map->sprite_texture.height) /\
		map->spr.sprite_height) / 256;
		color = my_mlx_pixel_take(&map->sprite_texture, map->spr.tex_x,\
		map->spr.tex_y);
		if (color)
			my_mlx_pixel_put(&map->img_win, map->spr.stripe, y, color);
		y++;
	}
}

void				sprite_assign(t_map *map, int i)
{
	map->spr.sprite_x = map->s_c[i].x - map->plr_x;
	map->spr.sprite_y = map->s_c[i].y - map->plr_y;
	map->spr.inv_det = 1.0 / (map->plane_x * map->dir_y -\
	map->dir_x * map->plane_y);
	map->spr.tran_x = map->spr.inv_det * (map->dir_y * map->spr.sprite_x -\
	map->dir_x * map->spr.sprite_y);
	map->spr.tran_y = map->spr.inv_det * (-map->plane_y * map->spr.sprite_x +\
	map->plane_x * map->spr.sprite_y);
	map->spr.spr_screen_x = (int)((map->r_x / 2) *\
	(1 + map->spr.tran_x / map->spr.tran_y));
	map->spr.sprite_height = abs((int)(map->r_y / (map->spr.tran_y)));
	map->spr.draw_start_y = -map->spr.sprite_height / 2 + map->r_y / 2;
	if (map->spr.draw_start_y < 0)
		map->spr.draw_start_y = 0;
	map->spr.draw_end_y = map->spr.sprite_height / 2 + map->r_y / 2;
	if (map->spr.draw_end_y >= map->r_y)
		map->spr.draw_end_y = map->r_y - 1;
	map->spr.sprite_width = abs((int)(map->r_y / (map->spr.tran_y)));
	map->spr.draw_start_x = -map->spr.sprite_width / 2 + map->spr.spr_screen_x;
	if (map->spr.draw_start_x < 0)
		map->spr.draw_start_x = 0;
	map->spr.draw_end_x = map->spr.sprite_width / 2 + map->spr.spr_screen_x;
	if (map->spr.draw_end_x >= map->r_x)
		map->spr.draw_end_x = map->r_x - 1;
	map->spr.stripe = map->spr.draw_start_x;
}

void				manage_sprite(t_map *map, double *zbuffer)
{
	int				i;

	i = 0;
	while (i < map->sprite_count)
	{
		sprite_assign(map, i);
		while (map->spr.stripe < map->spr.draw_end_x)
		{
			map->spr.tex_x = (int)(256 * (map->spr.stripe -\
			(-map->spr.sprite_width / 2 + map->spr.spr_screen_x)) *\
			map->sprite_texture.width / map->spr.sprite_width) / 256;
			if (map->spr.tran_y > 0 && map->spr.stripe > 0 &&\
			map->spr.stripe < map->r_x && map->spr.tran_y <\
			zbuffer[map->spr.stripe])
				draw_sprite(map);
			map->spr.stripe++;
		}
		i++;
	}
}

void				sprite(t_map *map, double *zbuffer)
{
	int				i;
	double			spritedistance[map->sprite_count];

	i = 0;
	while (i < map->sprite_count)
	{
		spritedistance[i] = ((map->plr_x - map->s_c[i].x) *\
			(map->plr_x - (map->s_c[i].x)) + (map->plr_y - map->s_c[i].y) *\
			(map->plr_y - map->s_c[i].y));
		i++;
	}
	sort_sprites(map);
	manage_sprite(map, zbuffer);
}
