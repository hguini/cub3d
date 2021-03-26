/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <hguini@student.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:31:11 by max               #+#    #+#             */
/*   Updated: 2020/11/07 14:51:33 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t count)
{
	unsigned int	i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	if (count == 0)
		return (0);
	temp1 = (unsigned char*)src1;
	temp2 = (unsigned char*)src2;
	while ((temp1[i] == temp2[i]) && i < (count - 1))
		i++;
	return (temp1[i] - temp2[i]);
}
