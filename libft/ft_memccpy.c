/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <hguini@student.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:30:32 by max               #+#    #+#             */
/*   Updated: 2020/11/13 12:08:36 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int s, size_t count)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	temp1 = (unsigned char*)dest;
	temp2 = (unsigned char*)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (count--)
	{
		temp1[i] = temp2[i];
		if (temp2[i] == (unsigned char)s)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
