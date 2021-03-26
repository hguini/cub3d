/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:16:22 by hguini            #+#    #+#             */
/*   Updated: 2021/03/26 06:03:05 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		skipping_symbol(t_map *map, char c, int i)
{
	while (map->line[i] != c)
	{
		if (map->line[i] == ' ' || map->line[i] == '\t')
			i++;
		else
			check_valid(c);
	}
	return (++i);
}

int		skipping_spaces(t_map *map, int i)
{
	while (map->line[i] == ' ' || map->line[i] == '\t')
		i++;
	return (i);
}

int		scipping_digits(t_map *map, int i)
{
	while (ft_isdigit(map->line[i]))
		i++;
	return (i);
}

void	manage_map(int fd, t_map *map)
{
	int i;

	i = 0;
	ft_if_map(map);
	free(map->line);
	while (get_next_line(fd, &map->line))
	{
		if (ft_strnstr(map->line, "1", ft_strlen(map->line)) ||
				ft_strnstr(map->line, " ", ft_strlen(map->line)))
			ft_if_map(map);
		else
			check_valid('M');
		while (map->line[i])
			i++;
		if (map->max < i)
			map->max = i;
		free(map->line);
	}
	free(map->line);
	map->map = ft_split(map->str, '*');
}

void	manage_parse(int fd, t_map *map)
{
	while (get_next_line(fd, &map->line))
	{
		if (ft_strnstr(map->line, "R", ft_strlen(map->line)))
			ft_if_r(map);
		else if (ft_strnstr(map->line, "NO", ft_strlen(map->line)))
			ft_if_no(map);
		else if (ft_strnstr(map->line, "SO", ft_strlen(map->line)))
			ft_if_so(map);
		else if (ft_strnstr(map->line, "WE", ft_strlen(map->line)))
			ft_if_we(map);
		else if (ft_strnstr(map->line, "EA", ft_strlen(map->line)))
			ft_if_ea(map);
		else if (ft_strnstr(map->line, "S", ft_strlen(map->line)))
			ft_if_s(map);
		else if (ft_strnstr(map->line, "F", ft_strlen(map->line)))
			ft_if_f(map);
		else if (ft_strnstr(map->line, "C", ft_strlen(map->line)))
			ft_if_c(map);
		else if (ft_strnstr(map->line, "1", ft_strlen(map->line)))
			manage_map(fd, map);
		else if (ft_strnstr(map->line, "\0", ft_strlen(map->line)))
			free(map->line);
		else
			check_valid('M');
	}
}
