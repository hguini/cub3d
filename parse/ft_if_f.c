/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:25:49 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 02:12:19 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_if_f(t_map *map)
{
	int			i;
	static int	flag;

	i = 0;
	i = skipping_symbol(map, 'F', i);
	i = skipping_spaces(map, i);
	map->f_r = ft_atoi(&map->line[i]);
	i = scipping_digits(map, i);
	while ((map->line[i] == ' ' || map->line[i] == '\t') && map->line[i] != ',')
		i++;
	map->f_g = ft_atoi(&map->line[++i]);
	i = scipping_digits(map, ++i);
	while ((map->line[i] == ' ' || map->line[i] == '\t') && map->line[i] != ',')
		i++;
	map->f_b = ft_atoi(&map->line[++i]);
	i = skipping_spaces(map, i);
	i = scipping_digits(map, i);
	if (map->f_r == -1 || map->f_r > 255 || map->f_g == -1 ||
		map->f_g > 255 || map->f_b == -1 || map->f_b > 255 ||
		flag || map->line[i] != '\0')
		check_valid('F');
	flag = 1;
	free(map->line);
}
