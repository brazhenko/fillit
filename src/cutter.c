/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 04:14:15 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/31 04:41:18 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**cutter(char* str, int f_c)
{
	char		**f_v;
	int			i;
	int			j;

	i = 0;
	j = 0;
	printf("%d\n", f_c);
	f_v = (char **)malloc(sizeof(char *) * (f_c + 1));
	f_v[f_c] = NULL;
	while (f_c)
	{
		if (!(f_v[i] = (char *)malloc(sizeof(char) * 17)))
		{
			printf("PIZDA!\n");
			return (NULL);
		}
		while (j < 16)
		{
			f_v[i][j] = str[16 * i + j];
			j++;
		}
		f_v[i][16] = 0;
		j = 0;
		i++;
		f_c--;
	}
	printf("%s\n%s\n%s\n", *f_v, *(f_v+1), *(f_v+2));
	return (f_v);
}
