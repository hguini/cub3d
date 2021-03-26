/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:25:23 by hguini            #+#    #+#             */
/*   Updated: 2021/03/26 05:29:48 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				get_len_digit(t_map *map, int i)
{
	int			len;

	len = 0;
	while (map->line[i] == '0')
		i++;
	while (ft_isdigit(map->line[i]))
	{
		len++;
		i++;
	}
	return (len);
}

void			ft_if_r(t_map *map)
{
	int			i;
	static int	flag;

	i = 0;
	i = skipping_symbol(map, 'R', i);
	i = skipping_spaces(map, i);
	if (get_len_digit(map, i) > 4)
		map->r_x = 9999;
	else
		map->r_x = ft_atoi(&map->line[i]);
	i = scipping_digits(map, i);
	i = skipping_spaces(map, i);
	if (get_len_digit(map, i) > 4)
		map->r_y = 9999;
	else
		map->r_y = ft_atoi(&map->line[i]);
	i = scipping_digits(map, i);
	if (!(map->r_x <= 0 || map->r_y <= 0 || flag || map->line[i] != '\0'))
		flag = 1;
	else
		check_valid('R');
	free(map->line);
}
