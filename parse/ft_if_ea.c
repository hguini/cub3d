/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_ea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:25:43 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 02:12:01 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_if_ea(t_map *map)
{
	int			i;
	static int	flag;

	i = 0;
	while (map->line[i] != 'E' && map->line[i + 1] != 'A')
	{
		if (map->line[i] != ' ' || map->line[i] != '\t')
			check_valid('T');
		i++;
	}
	i += 2;
	i = skipping_spaces(map, i);
	if (!(map->ea = ft_strdup(&map->line[i])) || flag)
		check_valid('T');
	flag = 1;
	free(map->line);
}
