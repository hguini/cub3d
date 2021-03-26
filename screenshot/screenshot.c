/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:38:58 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 03:51:55 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		filling_file_screenshot(int fd, t_map *map)
{
	int	i;
	int	j;
	int	color;

	i = map->r_y;
	while (--i >= 0)
	{
		j = -1;
		while (++j < map->r_x)
		{
			color = *(int*)(map->img_win.addr + (i * map->img_win.line_length
					+ j * (map->img_win.bits_per_pixel / 8)));
			write(fd, &color, 4);
		}
	}
}

void			continue_screenshot(t_map *map, int fd)
{
	int		size_screen;
	int		pos_pixel_data;
	int		zero;
	short	plane;

	plane = 1;
	zero = 0;
	pos_pixel_data = 54;
	size_screen = map->r_x
		* map->r_y * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pixel_data, 4);
	pos_pixel_data = 40;
	write(fd, &pos_pixel_data, 4);
	write(fd, &map->r_x, 4);
	write(fd, &map->r_y, 4);
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

void			screenshot(t_map *map)
{
	int fd;
	int size_screen;
	int zero;
	int size;

	fd = open("cub3d.bmp", O_CREAT | O_RDWR, 0666);
	size_screen = map->r_x
		* map->r_y * 4 + 54;
	zero = 0;
	size = map->r_x
		* map->r_y;
	if (fd < 0)
		check_valid('B');
	continue_screenshot(map, fd);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	size_screen = 1000;
	write(fd, &size_screen, 4);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	filling_file_screenshot(fd, map);
	close(fd);
}
