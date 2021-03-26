/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_so.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:25:36 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 02:12:49 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_if_so(t_map *map)
{
	int			i;
	static int	flag;

	i = 0;
	while (map->line[i] != 'S' && map->line[i + 1] != 'O')
	{
		if (map->line[i] != ' ' || map->line[i] != '\t')
			check_valid('T');
		i++;
	}
	i += 2;
	i = skipping_spaces(map, i);
	if (!(map->so = ft_strdup(&map->line[i])) || flag)
		check_valid('T');
	flag = 1;
	free(map->line);
}
