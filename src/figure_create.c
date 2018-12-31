/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:52:18 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/30 21:56:44 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		**freedel(char ***figure)
{
	int		i;

	i = 0;
	while (figure[i])
	{
		free(figure[i]);
		i += 1;
	}
	free(figure);
	return (NULL);
}

char			**figure_create(char *line)
{
	char	**figure;
	int		four;
	int		i;
	int		j;

	j = 0;
	i = 0;
	four = 0;
	if (!line)
		return (NULL);
	if (!(figure = (char**)malloc(sizeof(char*) * 4)))
		return (NULL);
	while (i < 4)
	{
		if (!(figure[i] = (char*)malloc(sizeof(char) * 5)))
			return (freedel(&figure));
		while (four < 4)
			figure[i][four++] = line[j++];
		figure[i][four] = '\0';
		four = 0;
		i += 1;
	}
	return (figure);
}
