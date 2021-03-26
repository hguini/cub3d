/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <hguini@student.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:27:53 by max               #+#    #+#             */
/*   Updated: 2020/11/13 12:04:29 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char*)malloc(n * size);
	if (!dest)
		return (NULL);
	while (i < n * size)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
