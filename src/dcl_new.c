/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 22:07:31 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/31 07:55:52 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_dc_list		*dcl_new(char **str)
{
	t_dc_list	*new;

	if (!(new = (t_dc_list *)malloc(sizeof(t_dc_list))))
		return (NULL);
	printf("CREATED!\n");
	new->next = NULL;
	new->prev = NULL;
	new->sign = 'A';
	new->figure = str;
	return (new);
}
