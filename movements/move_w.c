/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 03:02:01 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 03:28:33 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_w(t_map *map, float movespeed)
{
	if (map->map[(int)(map->plr_x + map->dir_x * movespeed)]\
	[(int)(map->plr_y)] == '0')
		map->plr_x += map->dir_x * movespeed;
	if (map->map[(int)(map->plr_x)][(int)(map->plr_y +\
	map->dir_y * movespeed)] == '0')
		map->plr_y += map->dir_y * movespeed;
}
