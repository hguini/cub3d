/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:30:50 by max               #+#    #+#             */
/*   Updated: 2020/11/24 17:13:06 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int s, size_t count)
{
	unsigned char	*ptr;
	unsigned int	start;

	ptr = (unsigned char*)src;
	start = 0;
	while (start < count)
	{
		if (ptr[start] == (unsigned char)s)
		{
			return (&ptr[start]);
		}
		start++;
	}
	return (NULL);
}
