/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:32:11 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/02 08:56:43 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int				main(int c, char **v)
{
	if (c == 2)
	{
		int				fd;
		t_dc_list		*fig_vector;
		int				min_size;
		char			**e_f = (char **)malloc(sizeof(char *) * 4);

		*(e_f + 0) = "....\0";
		*(e_f + 1) = "....\0";
		*(e_f + 2) = "....\0";
		*(e_f + 3) = "....\0";
		fig_vector = dcl_new(e_f);
		fig_vector->sign = '@';
		fd = open(v[1], O_RDONLY);
		int f_c = check_n_fill(fd, &fig_vector);
		min_size = min_sz(f_c);
		printf("F_C: %d\nMIN_SZ: %d\n", f_c, min_size);

		write(1, "_________\n", 10);

		dcl_rewind(&fig_vector);
		// forward_printer(&fig_vector);
		if (1 <= f_c && f_c <= 26)
		{
			filler(f_c, min_size, fig_vector->next);
		}
	}
	else
	{
		ft_putendl("usage: ./fillit file");
	}
	return (0);
}
