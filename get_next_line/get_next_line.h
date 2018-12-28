/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:21:16 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/24 02:59:46 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 7
# define FD_MAX 5000
# include "libft/libft.h"

typedef	struct		s_string
{
	char	*text;
	char	*begin;
}					t_string;

int					get_next_line(const int fd, char **line);
char				*ft_strchr(const char *s, int c);

#endif
