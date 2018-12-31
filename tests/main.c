/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:12:12 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/29 18:24:42 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char		**figure_create(char *line);

int			main(void)
{
	char	line[] = "...#...#..##....";
	int		i;
	char	**str;

	str = figure_create(line);
	i = 0;
	while (i < 4)
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}
