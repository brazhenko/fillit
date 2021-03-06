/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_one_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 22:00:06 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/03 00:11:46 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		val_coors(int x, int y)
{
	if (0 <= x && x <= 3 && 0 <= y && y <= 3)
		return (1);
	return (0);
}

static int		val_neig_vector(char *v)
{
	int c1;
	int c2;
	int c3;

	c1 = 0;
	c2 = 0;
	c3 = 0;
	while (*v)
	{
		if (*v == '1')
			c1++;
		else if (*v == '2')
			c2++;
		else if (*v == '3')
			c3++;
		v++;
	}
	if (c1 == 2 && c2 == 2 && c3 == 0)
		return (1);
	else if (c1 == 0 && c2 == 4 && c3 == 0)
		return (1);
	else if (c1 == 3 && c2 == 0 && c3 == 1)
		return (1);
	return (0);
}

static void		hash_handle(char ***fig, int *i, int *j, int *one_cell_c)
{
	if (val_coors(*i + 1, *j) && (*fig)[*i + 1][*j] == '#')
		(*one_cell_c)++;
	if (val_coors(*i, *j + 1) && (*fig)[*i][*j + 1] == '#')
		(*one_cell_c)++;
	if (val_coors(*i - 1, *j) && (*fig)[*i - 1][*j] == '#')
		(*one_cell_c)++;
	if (val_coors(*i, *j - 1) && (*fig)[*i][*j - 1] == '#')
		(*one_cell_c)++;
}

static void		var_nuller(int *i, int *j, int *count, int *one_cell_c)
{
	*i = -1;
	*j = -1;
	*count = 0;
	*one_cell_c = 0;
}

int				val_one_figure(char **fig)
{
	int		i;
	int		j;
	int		count;
	int		one_cell_c;
	char	*fill_vector;

	var_nuller(&i, &j, &count, &one_cell_c);
	fill_vector = ft_strnew(5);
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (fig[i][j] == '#')
			{
				hash_handle(&fig, &i, &j, &one_cell_c);
				count++;
				fill_vector[count - 1] = one_cell_c + '0';
			}
			one_cell_c = 0;
		}
		j = -1;
	}
	if (count == 4 && val_neig_vector(fill_vector))
		return (1);
	return (0);
}
