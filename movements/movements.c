/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:56:13 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 06:56:39 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		close_window(t_map *map)
{
	(void)map;
	exit(1);
}

void	after_hook(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img_win.img);
	map->img_win.img = mlx_new_image(map->mlx, map->r_x, map->r_y);
	map->img_win.addr = mlx_get_data_addr(map->img_win.img,\
	&map->img_win.bits_per_pixel, &map->img_win.line_length,\
	&map->img_win.endian);
	draw_map(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img_win.img, 0, 0);
}

int		key_hook(int keycode, t_map *map)
{
	float	movespeed;
	float	rotspeed;

	movespeed = 0.1;
	rotspeed = 0.1;
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
		move_w(map, movespeed);
	if (keycode == 1)
		move_s(map, movespeed);
	if (keycode == 2)
		move_d(map, movespeed);
	if (keycode == 0)
		move_a(map, movespeed);
	if (keycode == 124)
		rotation_right(map, rotspeed);
	if (keycode == 123)
		rotation_left(map, rotspeed);
	after_hook(map);
	return (1);
}
