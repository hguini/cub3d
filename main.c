/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:27:00 by hguini            #+#    #+#             */
/*   Updated: 2021/03/26 05:59:29 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_all(t_map *map)
{
	map->line = NULL;
	map->r_x = -1;
	map->r_y = -1;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->s = 0;
	map->f_r = -1;
	map->f_g = -1;
	map->f_b = -1;
	map->c_r = -1;
	map->c_g = -1;
	map->c_b = -1;
	map->map = 0;
	map->mlx = NULL;
	map->win = NULL;
	map->count_line = -1;
	map->max = 0;
	map->width = 64;
	map->height = 64;
}

void		get_screen_size(t_map *map)
{
	int x;
	int y;

	mlx_get_screen_size(map->mlx, &x, &y);
	if (map->r_x > x)
		map->r_x = x;
	if (map->r_y > y)
		map->r_y = y;
}

void		ft_window(t_map *map, int argc)
{
	map->mlx = mlx_init();
	filling_texture_img(map);
	get_screen_size(map);
	map->win = mlx_new_window(map->mlx, map->r_x, map->r_y, "CUBDDD");
	map->img_win.img = mlx_new_image(map->mlx, map->r_x, map->r_y);
	map->img_win.addr = mlx_get_data_addr(map->img_win.img, &map->img_win.\
	bits_per_pixel, &map->img_win.line_length, &map->img_win.endian);
	if (argc == 3)
	{
		draw_map(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img_win.img, 0, 0);
		screenshot(map);
	}
	else
	{
		draw_map(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img_win.img, 0, 0);
		mlx_hook(map->win, 2, 1L << 0, key_hook, map);
		mlx_hook(map->win, 17, 1L << 0, close_window, map);
		mlx_loop(map->mlx);
	}
}

int			main(int argc, char **argv)
{
	int			fd;
	t_map		map;

	if (!(map.str = ft_strdup("")))
		check_valid('m');
	if (argc < 4 && argc > 1 && check_file(argv[1]) &&
		(argv[2] == NULL || ft_strncmp(argv[2], "--save", 7) == 0))
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			check_valid('A');
		fd = open(argv[1], O_RDONLY);
		init_all(&map);
		manage_parse(fd, &map);
		check_map(&map);
		ft_pos_player(&map);
		side_plr(&map);
		sprite_counter(&map);
	}
	else
		check_valid('A');
	ft_window(&map, argc);
}
