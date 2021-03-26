/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:47:34 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 00:48:11 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		side_plr(t_map *map)
{
	if (map->light_side == 'N')
	{
		map->dir_x = -1;
		map->plane_y = 0.66;
	}
	if (map->light_side == 'S')
	{
		map->dir_x = 1;
		map->plane_y = -0.66;
	}
	if (map->light_side == 'W')
	{
		map->dir_y = -1;
		map->plane_x = -0.66;
	}
	if (map->light_side == 'E')
	{
		map->dir_y = 1;
		map->plane_x = 0.66;
	}
}
