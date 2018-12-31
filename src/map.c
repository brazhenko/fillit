/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:02:26 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/31 10:04:19 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		**free_map(char ***map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i += 1;
	}
	free(map);
	return (NULL);
}

char			**map_gen(void)
{
	char	**map;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * 21)))
		return (NULL);
	while (i < 21)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * 22)))
			return (free_map(&map));
		while (j < 22)
			map[i][j++] = '.';
		map[i][j] = '\0';
		j = 0;
		i += 1;
	}
	return (map);
}
