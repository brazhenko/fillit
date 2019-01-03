/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:32:11 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/03 00:17:43 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			**coord_allocator(int f_c)
{
	char				**coordinates;

	coordinates = (char **)malloc(f_c * sizeof(char *));
	while (f_c)
	{
		coordinates[f_c - 1] = (char *)malloc(2);
		coordinates[f_c - 1][0] = 0;
		coordinates[f_c - 1][1] = 0;
		f_c--;
	}
	return (coordinates);
}

int					main(int c, char **v)
{
	int				fd;
	t_dc_list		*fig_vector;
	int				min_size;
	int				f_c;

	if (c == 2)
	{
		fig_vector = dcl_new(NULL);
		fig_vector->sign = '@';
		fd = open(v[1], O_RDONLY);
		f_c = check_n_fill(fd, &fig_vector);
		min_size = min_sz(f_c);
		dcl_rewind(&fig_vector);
		if (1 <= f_c && f_c <= 26)
			filler(f_c, min_size, fig_vector->next, coord_allocator(f_c));
		else
			ft_putendl("error");
	}
	else
	{
		ft_putendl("usage: ./fillit file");
	}
	return (0);
}
