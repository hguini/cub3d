/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 03:10:01 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 03:28:48 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_a(t_map *map, float movespeed)
{
	if (map->map[(int)(map->plr_x - map->dir_y * movespeed)]\
	[(int)(map->plr_y)] == '0')
		map->plr_x -= map->dir_y * movespeed;
	if (map->map[(int)(map->plr_x)][(int)(map->plr_y +\
	map->dir_x * movespeed)] == '0')
		map->plr_y += map->dir_x * movespeed;
}
