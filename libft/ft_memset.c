/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <hguini@student.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:39:49 by max               #+#    #+#             */
/*   Updated: 2020/11/07 14:44:29 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int sym, size_t num)
{
	unsigned char	*dest;

	dest = (unsigned char*)src;
	while (num > 0)
	{
		num--;
		dest[num] = (unsigned char)sym;
	}
	return (dest);
}
