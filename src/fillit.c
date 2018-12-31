/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:32:11 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/31 10:31:38 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int				main(int c, char **v)
{
	if (c == 2)
	{
		int				fd;
		t_dc_list		*fig_vector;


		fig_vector = dcl_new(NULL);
		fig_vector->sign = '@';
		fd = open(v[1], O_RDONLY);
		int res = check_n_fill(fd, &fig_vector);
		printf("%d\n", res);

		write(1, "_________\n", 10);

		// dcl_rewind(&fig_vector);
		// forward_printer(&fig_vector);
	
		filler(4, 4, fig_vector->prev->prev);
		
	}
	return (0);
}
