/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 02:13:47 by hharrold          #+#    #+#             */
/*   Updated: 2019/01/01 23:14:00 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void		forward_printer(t_dc_list **fig)
{
	while ((*fig))
	{
		printf("\nFIGURE : %c\n\n", (*fig)->sign);
		
		if ((*fig)->sign != '@')
		{
			// printf("PTR2: %p\n", (*fig)->figure);
			// printf("IM HERE: %s\n", (((*fig)->figure))[0]);
			// printf("IM HERE: %s\n", (((*fig)->figure))[1]);
			// printf("IM HERE: %s\n", (((*fig)->figure))[2]);
			// printf("IM HERE: %s\n\n", (((*fig)->figure))[3]);
		}
		(*fig) = (*fig)->next;
	}
}
