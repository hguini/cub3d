/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:17:19 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 02:48:10 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		sprite_counter_sec(t_map *map)
{
	int		i;
	int		j;
	int		h;

	i = 0;
	j = 0;
	h = 0;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '2')
			{
				map->s_c[h].x = i + 0.5;
				map->s_c[h].y = j + 0.5;
				h++;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void		sprite_counter(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map->sprite_count = 0;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '2')
				map->sprite_count += 1;
			j++;
		}
		i++;
		j = 0;
	}
	map->s_c = ft_calloc(sizeof(t_sprite), map->sprite_count + 1);
	sprite_counter_sec(map);
}

void		count_sprite_dst(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->sprite_count)
	{
		map->s_c[i].dis = \
			((map->plr_x - map->s_c[i].x) * \
			(map->plr_x - map->s_c[i].x) + \
			(map->plr_y - map->s_c[i].y) * \
			(map->plr_y - map->s_c[i].y));
		i++;
	}
}

void		swap_sprites(t_map *map, int j, int i)
{
	float	tmp;
	float	position;

	tmp = 0;
	position = 0;
	tmp = map->s_c[j].dis;
	map->s_c[j].dis = map->s_c[i].dis;
	map->s_c[i].dis = tmp;
	position = map->s_c[i].x;
	map->s_c[i].x = map->s_c[j].x;
	map->s_c[j].x = position;
	position = map->s_c[i].y;
	map->s_c[i].y = map->s_c[j].y;
	map->s_c[j].y = position;
}

void		sort_sprites(t_map *map)
{
	int		i;
	int		j;

	count_sprite_dst(map);
	j = 0;
	while (j < map->sprite_count)
	{
		i = 0;
		while (i < map->sprite_count)
		{
			if (map->s_c[j].dis > map->s_c[i].dis)
				swap_sprites(map, i, j);
			i++;
		}
		j++;
	}
}
