/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_take.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 06:48:05 by hguini            #+#    #+#             */
/*   Updated: 2021/03/19 06:48:50 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	my_mlx_pixel_take(t_img *img, int x, int y)
{
	char		*dst;

	dst = img->addr + (y * img->line_length +\
	x * (img->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}
