/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:42:50 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/24 11:24:49 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>

static int			ft_strlen_bsn(char *str)
{
	int len;

	len = 0;
	while (*str && *str != '\n')
	{
		len++;
		str++;
	}
	return (len);
}

static t_string		*create_t_string(void)
{
	t_string *s;

	s = (t_string *)malloc(sizeof(t_string));
	s->text = ft_strnew(1);
	return (s);
}

static int			costyl(t_string **str1, t_string **buf_fd, int fd)
{
	char *str2;
	char *str3;

	str2 = ft_strnew(BUFF_SIZE);
	*str1 = create_t_string();
	if (read(fd, NULL, 0) == -1)
		return (-1);
	while (read(fd, str2, BUFF_SIZE))
	{
		{
			str3 = (*str1)->text;
			if (!((*str1)->text = ft_strjoin((const char *)((*str1)->text), \
									(const char *)str2)))
				return (-1);
			free(str3);
			free(str2);
			str2 = ft_strnew(BUFF_SIZE);
		}
	}
	free(str2);
	*buf_fd = *str1;
	(*str1)->begin = (*str1)->text;
	return (1);
}

static int			costyl2(t_string **buf)
{
	*buf = NULL;
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_string				*buf[FD_MAX];
	int							str_len;
	t_string					*str1;

	if (fd < 0 || !line || FD_MAX < fd)
		return (-1);
	if (!buf[fd])
		if (costyl(&str1, &(buf[fd]), fd) == -1)
			return (-1);
	str_len = ft_strlen_bsn(buf[fd]->text);
	if (!(*(buf[fd]->text)))
		return (costyl2(&(buf[fd])));
	if (!(*line = (char *)malloc(str_len + 1)))
		return (-1);
	while (*(buf[fd]->text) && *(buf[fd]->text) != '\n')
	{
		**line = *(buf[fd]->text);
		(buf[fd]->text)++;
		(*line)++;
	}
	**line = 0;
	(*line) -= str_len;
	if (*(buf[fd]->text) == '\n')
		(buf[fd]->text)++;
	return (1);
}
