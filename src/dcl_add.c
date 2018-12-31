/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcl_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 22:49:00 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/31 10:31:43 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	dcl_add(t_dc_list **left, t_dc_list *right)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	write(1, "TRY ADD\n", 8);
	
	while ((*left)->next != NULL)
		(*left) = (*left)->next;
	right->prev = (*left);
	right->sign = (*left)->sign + 1;
	printf("CHECK: %c\n", (*left)->sign);
	while (i < 4)
	{
		while (j < 4)
		{
			if ((right->figure)[i][j] == '#')
				(right->figure)[i][j] = right->sign;
			j++;
		}
		j = 0;
		i++;
	}
	(*left)->next = right;
}
