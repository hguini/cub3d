/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <hguini@student.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:34:26 by max               #+#    #+#             */
/*   Updated: 2020/11/07 14:34:28 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	int	i;
	int	h;

	i = 0;
	h = -1;
	if (str[i] == sym && sym == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		if (str[i] == sym)
			h = i;
		i++;
	}
	if (str[i] == sym)
		return ((char*)(str + i));
	if (h == -1)
		return (NULL);
	else
		return ((char*)(str + h));
}
