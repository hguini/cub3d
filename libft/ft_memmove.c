/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <hguini@student.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:36:51 by max               #+#    #+#             */
/*   Updated: 2020/11/07 14:50:38 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (s == d)
		return (dest);
	if (s < d)
	{
		s = (unsigned char*)src + count - 1;
		d = dest + count - 1;
		while (count--)
			*d-- = *s--;
	}
	else
	{
		while (count--)
			*d++ = *s++;
	}
	return (dest);
}
