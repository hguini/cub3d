/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 03:07:42 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 03:28:03 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_s(t_map *map, float movespeed)
{
	if (map->map[(int)(map->plr_x - map->dir_x * movespeed)]\
	[(int)(map->plr_y)] == '0')
		map->plr_x -= map->dir_x * movespeed;
	if (map->map[(int)(map->plr_x)][(int)(map->plr_y -\
	map->dir_y * movespeed)] == '0')
		map->plr_y -= map->dir_y * movespeed;
}
