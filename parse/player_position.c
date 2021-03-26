/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:50:45 by hguini            #+#    #+#             */
/*   Updated: 2021/03/22 16:14:07 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pos_assign(t_map *map, int i, int j)
{
	map->plr_x = i + 0.5;
	map->plr_y = j + 0.5;
	map->light_side = map->map[i][j];
	map->map[i][j] = '0';
}

void	ft_pos_player(t_map *map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' ||
				map->map[i][j] == 'W' || map->map[i][j] == 'E')
			{
				pos_assign(map, i, j);
				flag++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (flag != 1)
		check_valid('P');
}
