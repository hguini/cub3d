/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 03:12:07 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 03:30:08 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotation_right(t_map *map, float rotspeed)
{
	float	old_dirx;
	float	old_planex;

	old_dirx = map->dir_x;
	map->dir_x = map->dir_x * cos(-rotspeed) - map->dir_y * sin(-rotspeed);
	map->dir_y = old_dirx * sin(-rotspeed) + map->dir_y * cos(-rotspeed);
	old_planex = map->plane_x;
	map->plane_x = map->plane_x * cos(-rotspeed) -\
	map->plane_y * sin(-rotspeed);
	map->plane_y = old_planex * sin(-rotspeed) + map->plane_y * cos(-rotspeed);
}
