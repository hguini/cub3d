/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:03:04 by hguini            #+#    #+#             */
/*   Updated: 2020/11/24 19:14:03 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && (s[i] == c || s[i] != '\0'))
			{
				i++;
			}
		}
	}
	return (count);
}

static int		ft_count_letter(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static void		*ft_duckhead_free(char **str, int i)
{
	while (i >= 0)
		free(str[--i]);
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	int			word;
	char		**str;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	word = ft_count_word(s, c);
	if (!(str = malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	while (++i < word)
	{
		while (*s == c)
			s++;
		if (!(str[i] = malloc(sizeof(char) * (ft_count_letter(s, c) + 1))))
			return (ft_duckhead_free(str, i));
		while (*s != c && *s)
			str[i][j++] = *(s++);
		str[i][j] = '\0';
		j = 0;
	}
	str[i] = NULL;
	return (str);
}
