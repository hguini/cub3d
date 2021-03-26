/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:27:45 by hguini            #+#    #+#             */
/*   Updated: 2021/03/23 23:42:01 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_if_map(t_map *map)
{
	int		i;
	char	*tmp;

	tmp = map->str;
	i = 0;
	if ((map->str = ft_strjoin(map->str, map->line)))
	{
		while (map->str[i])
			i++;
		map->str[i] = '*';
		map->str[i + 1] = '\0';
		map->count_line++;
	}
	else
		check_valid('M');
	free(tmp);
}
