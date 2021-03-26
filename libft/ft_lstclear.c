/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:02:02 by hguini            #+#    #+#             */
/*   Updated: 2020/11/17 18:47:58 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elm;

	if (!del || !*lst)
		return ;
	while (*lst)
	{
		elm = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = elm;
	}
}
