/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <hguini@student.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:48:31 by max               #+#    #+#             */
/*   Updated: 2020/11/07 14:47:42 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t num)
{
	size_t			i;
	unsigned char	*dest;

	i = num;
	dest = (unsigned char*)src;
	while (i > 0)
	{
		i--;
		dest[i] = 0;
	}
	src = dest;
}
