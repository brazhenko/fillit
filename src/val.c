/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:14:32 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/31 09:25:03 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int				val_map(char **map, int size)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 21)
	{
		while (j < 21)
		{
			if (map[i][j] != '.')
			{
				if (i < 3 || (3 + size) <= i)
					return (0);
				if (j < 3 || (3 + size) <= j)
					return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}