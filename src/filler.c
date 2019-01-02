/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 08:32:42 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/02 08:56:45 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			print_map(char **map, int sz)
{
	int			i;
	int			j;

	i = 3;
	j = 3;
	while (i < 3 + sz)
	{
		while (j < 3 + sz)
		{
			write(1, &(map[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 3;
	}
}

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

int					is_able_to_place(char ***map, char **fig, char x, \
														char y, int sz)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (((*map)[x + i][y + j] != '.' && fig[i][j] != '.'))
				return (0);
			else if (fig[i][j] != '.')
			{
				if ((x + i) < 3 || 2 + sz < (x + i) \
					|| (y + j) < 3 || 2 + sz < (y + j))
					return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int					place_one_figure(char ***map, char **fig, char x, \
													char y, int sz)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (is_able_to_place(map, fig, x, y, sz) == 0)
		return (0);
	while (i < 4)
	{
		while (j < 4)
		{
			if (fig[i][j] != '.')
				(*map)[x + i][y + j] = fig[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static void			null_coord_vector(char ***c, int f_c, int *sz, int bar)
{
	while (f_c > bar + 1)
	{
		(*c)[f_c - 1][0] = 0;
		(*c)[f_c - 1][1] = 0;
		f_c--;
	}
	if ((*c)[bar][0] == *sz + 2 && (*c)[bar][1] == *sz + 2)
	{
		if (bar == 0)
		{
			(*c)[0][0] = 0;
			(*c)[0][1] = 0;
			(*sz)++;
		}
		else
			null_coord_vector(c, f_c, sz, bar - 1);
	}
	else if ((*c)[bar][1] == *sz + 2)
	{
		(*c)[bar][0]++;
		(*c)[bar][1] = 0;
	}
	else
	{
		(*c)[bar][1]++;
	}
}

void				filler(int f_c, int sz, t_dc_list *n)
{
	static char			**map;
	char				**c;

	map = map_gen();
	// print_map(map, sz);
	// printf("\n");
	c = coord_allocator(f_c);
	while (n)
	{
		while (!place_one_figure(&map, n->figure, c[n->sign - 'A'][0], \
				c[n->sign - 'A'][1], sz))
		{
			if (c[n->sign - 'A'][0] == sz + 2 && c[n->sign - 'A'][1] == sz + 2)
			{
				null_coord_vector(&c, f_c, &sz, n->sign - 'A');
				if (n->sign != 'A')
					n = n->prev;
				map_eraser(&map, n->sign - 1, sz);
			}
			else if (c[n->sign - 'A'][1] == sz + 2)
			{
				c[n->sign - 'A'][0]++;
				c[n->sign - 'A'][1] = 0;
			}
			else
				c[n->sign - 'A'][1]++;
		}
		n = n->next;
	}
	print_map(map, sz);
}
