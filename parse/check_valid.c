/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 00:52:29 by hguini            #+#    #+#             */
/*   Updated: 2021/03/26 05:21:46 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		check_valid(char spec)
{
	if (spec == 'A')
		ft_putstr_fd("Error\ninvalid arguments\n", 1);
	else if (spec == 'R')
		ft_putstr_fd("Error\ninvalid resolution\n", 1);
	else if (spec == 'T')
		ft_putstr_fd("Error\ninvalid texture\n", 1);
	else if (spec == 'F')
		ft_putstr_fd("Error\ninvalid floor\n", 1);
	else if (spec == 'C')
		ft_putstr_fd("Error\ninvalid ceiling\n", 1);
	else if (spec == 'M')
		ft_putstr_fd("Error\ninvalid map\n", 1);
	else if (spec == 'P')
		ft_putstr_fd("Error\ninvalid player position\n", 1);
	else if (spec == 'B')
		ft_putstr_fd("Error\ninvalid screenshot\n", 1);
	else if (spec == 'X')
		ft_putstr_fd("Error\ninvalid file\n", 1);
	else if (spec == 'm')
		ft_putstr_fd("Error\nmemory error\n", 1);
	exit(1);
}
