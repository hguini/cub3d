/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:25:51 by hguini            #+#    #+#             */
/*   Updated: 2021/03/23 23:28:03 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_if_c(t_map *map)
{
	int			i;
	static int	flag;

	i = 0;
	i = skipping_symbol(map, 'C', i);
	i = skipping_spaces(map, i);
	map->c_r = ft_atoi(&map->line[i]);
	i = scipping_digits(map, i);
	while ((map->line[i] == ' ' || map->line[i] == '\t') && map->line[i] != ',')
		i++;
	map->c_g = ft_atoi(&map->line[++i]);
	i = scipping_digits(map, ++i);
	while ((map->line[i] == ' ' || map->line[i] == '\t') && map->line[i] != ',')
		i++;
	map->c_b = ft_atoi(&map->line[++i]);
	i = skipping_spaces(map, i);
	i = scipping_digits(map, i);
	if (map->c_r == -1 || map->c_r > 255 || map->c_g == -1 ||
		map->c_g > 255 || map->c_b == -1 || map->c_b > 255 ||
		flag || map->line[i] != '\0')
		check_valid('C');
	flag = 1;
	free(map->line);
}
