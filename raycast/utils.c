/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 06:03:13 by hguini            #+#    #+#             */
/*   Updated: 2021/03/25 01:00:30 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			twenty_sixth_line(t_map *map)
{
	if (map->side == 0)
		map->perpwalldist = (map->map_x - map->plr_x +\
			(1 - map->step_x) / 2) / map->raydir_x;
	else
		map->perpwalldist = (map->map_y - map->plr_y +\
		(1 - map->step_y) / 2) / map->raydir_y;
}

void			map_assign_again(t_map *map)
{
	twenty_sixth_line(map);
	map->lineheight = (int)(map->r_y / map->perpwalldist);
	map->drawstart = -map->lineheight / 2 + map->r_y / 2;
	if (map->drawstart < 0)
		map->drawstart = 0;
	map->drawend = map->lineheight / 2 + map->r_y / 2;
	if (map->drawend >= map->r_y)
		map->drawend = map->r_y - 1;
	if (map->side == 0)
		map->wall_x = map->plr_y + map->perpwalldist * map->raydir_y;
	else
		map->wall_x = map->plr_x + map->perpwalldist * map->raydir_x;
	map->wall_x -= floor((map->wall_x));
	map->tex_x = (int)(map->wall_x * (double)(map->width));
	if (map->side == 0 && map->raydir_x > 0)
		map->tex_x = map->width - map->tex_x - 1;
	if (map->side == 1 && map->raydir_y < 0)
		map->tex_x = map->width - map->tex_x - 1;
	map->step = 1.0 * map->height / map->lineheight;
	map->texpos = (map->drawstart - map->r_y / 2 +\
	map->lineheight / 2) * map->step;
}

void			check_hit(t_map *map)
{
	map->hit = 0;
	while (map->hit == 0)
	{
		if (map->sidedist_x < map->sidedist_y)
		{
			map->sidedist_x += map->deltadist_x;
			map->map_x += map->step_x;
			map->side = 0;
		}
		else
		{
			map->sidedist_y += map->deltadist_y;
			map->map_y += map->step_y;
			map->side = 1;
		}
		if (map->map[map->map_x][map->map_y] == '1')
			map->hit = 1;
	}
	map_assign_again(map);
}

void			step_sidedist(t_map *map)
{
	if (map->raydir_x < 0)
	{
		map->step_x = -1;
		map->sidedist_x = (map->plr_x - map->map_x) * map->deltadist_x;
	}
	else
	{
		map->step_x = 1;
		map->sidedist_x = (map->map_x + 1.0 - map->plr_x) * map->deltadist_x;
	}
	if (map->raydir_y < 0)
	{
		map->step_y = -1;
		map->sidedist_y = (map->plr_y - map->map_y) * map->deltadist_y;
	}
	else
	{
		map->step_y = 1;
		map->sidedist_y = (map->map_y + 1.0 - map->plr_y) * map->deltadist_y;
	}
	check_hit(map);
}

void			map_assign(t_map *map)
{
	map->camera_x = 2 * map->x / (float)map->r_x - 1;
	map->raydir_x = map->dir_x + map->plane_x * map->camera_x;
	map->raydir_y = map->dir_y + map->plane_y * map->camera_x;
	map->map_x = (int)(map->plr_x);
	map->map_y = (int)(map->plr_y);
	map->deltadist_x = sqrt(1 + (map->raydir_y * map->raydir_y) /\
	(map->raydir_x * map->raydir_x));
	map->deltadist_y = sqrt(1 + (map->raydir_x * map->raydir_x) /\
	(map->raydir_y * map->raydir_y));
	step_sidedist(map);
}
