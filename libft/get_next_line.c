/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:57:00 by hguini            #+#    #+#             */
/*   Updated: 2021/03/26 06:12:00 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../cub3d.h"
#define BUFFER_SIZE 10

static char				*check_remainder(char **remainder, char **line)
{
	char				*p_n;
	char				*tmp;

	p_n = NULL;
	if (*remainder)
	{
		if ((p_n = ft_strchr(*remainder, '\n')))
		{
			*p_n = '\0';
			tmp = *remainder;
			*line = ft_strdup(*remainder);
			*remainder = ft_strdup(++p_n);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

static int				cleaning_company(char *p_n, char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	if (p_n)
		return (1);
	else
		return (0);
}

static int				clear_buf(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	return (-1);
}

static void				check_read(int reading)
{
	if (reading == -1)
		check_valid('X');
}

int						get_next_line(int fd, char **line)
{
	static char			*remainder;
	char				*buf;
	char				*p_n;
	char				*tmp;
	int					reading;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	p_n = check_remainder(&remainder, line);
	while (!p_n && (reading = read(fd, buf, BUFFER_SIZE)))
	{
		check_read(reading);
		buf[reading] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			if (!(remainder = ft_strdup(++p_n)))
				return (clear_buf(buf));
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (clear_buf(buf));
		free(tmp);
	}
	return (cleaning_company(p_n, buf));
}
