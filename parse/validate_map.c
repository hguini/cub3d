/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 22:08:23 by hguini            #+#    #+#             */
/*   Updated: 2021/03/24 00:28:05 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		filling_spaces(t_map *map)
{
	int		count_spaces;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	count_spaces = 0;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
			j++;
		count_spaces = map->max - j;
		while (count_spaces--)
		{
			tmp = map->map[i];
			map->map[i] = ft_strjoin(map->map[i], " ");
			j++;
			free(tmp);
		}
		i++;
		j = 0;
	}
}

int			check_sym(char sym)
{
	if (sym == '0' || sym == '1' || sym == '2' ||
		sym == 'N' || sym == 'S' || sym == 'E' ||
		sym == 'W')
		return (1);
	return (0);
}

int			check_around(t_map *map, int i, int j)
{
	if (check_sym(map->map[i + 1][j]) == 1 &&
		check_sym(map->map[i - 1][j]) == 1 &&
		check_sym(map->map[i][j + 1]) == 1 &&
		check_sym(map->map[i][j - 1]) == 1 &&
		check_sym(map->map[i - 1][j + 1]) == 1 &&
		check_sym(map->map[i + 1][j - 1]) == 1 &&
		check_sym(map->map[i + 1][j + 1]) == 1 &&
		check_sym(map->map[i - 1][j - 1]) == 1)
		return (1);
	else
		check_valid('M');
	return (0);
}

void		check_walls(t_map *map)
{
	int		j;

	j = 0;
	while (map->map[0][j] != '\0')
	{
		if (map->map[0][j] != ' ' &&
			map->map[0][j] != '\t' &&
			map->map[0][j] != '1')
			check_valid('M');
		j++;
	}
	j = 0;
	while (map->map[map->count_line][j] != '\0')
	{
		if (map->map[map->count_line][j] != ' ' &&
			map->map[map->count_line][j] != '\t' &&
			map->map[map->count_line][j] != '1')
			check_valid('M');
		j++;
	}
}

void		check_map(t_map *map)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	filling_spaces(map);
	check_walls(map);
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '0' || map->map[i][j] == '2' ||
				map->map[i][j] == 'N' || map->map[i][j] == 'S' ||
				map->map[i][j] == 'W' || map->map[i][j] == 'E')
				check_around(map, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}
