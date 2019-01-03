/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:10:08 by lreznak-          #+#    #+#             */
/*   Updated: 2019/01/02 22:34:35 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		dots_n_sharps_only(char *str)
{
	while (*str)
	{
		if (*str != '.' && *str != '#')
			return (0);
		str++;
	}
	return (1);
}

static int		figures_handle(char *figures, t_dc_list **fv, int *f_c)
{
	char		*fig_cpy;
	int			fig_count;
	int			i;
	char		**fig_v;
	char		**one_fig;

	i = 0;
	fig_cpy = figures;
	fig_count = ft_strlen(figures) / 16;
	*f_c = fig_count;
	fig_v = cutter(figures, fig_count);
	while (*fig_v)
	{
		one_fig = figure_create(*fig_v);
		if (val_one_figure(one_fig))
		{
			dcl_add(fv, dcl_new(one_fig));
		}
		else
			return (0);
		fig_v++;
	}
	return (1);
}

int				check_n_fill(int fd, t_dc_list **node)
{
	char	*str;
	int		line_c;
	char	*figures;
	char	*temp_figures;
	int		f_c;

	figures = ft_strnew(1);
	line_c = 1;
	f_c = 0;
	while (get_next_line(fd, &str))
	{
		if (line_c % 5 == 0 && ft_strlen(str) != 0)
			return (0);
		else if (line_c % 5)
			if (ft_strlen(str) != 4 || dots_n_sharps_only(str) != 1)
				return (0);
		temp_figures = figures;
		figures = ft_strjoin(figures, str);
		free(temp_figures);
		free(str);
		line_c++;
	}
	if (line_c != 1 && line_c % 5 == 0 && figures_handle(figures, node, &f_c))
		return (f_c);
	return (0);
}
