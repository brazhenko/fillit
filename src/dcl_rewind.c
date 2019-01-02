/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dcl_rewind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 10:05:35 by hharrold          #+#    #+#             */
/*   Updated: 2019/01/01 21:37:20 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			dcl_rewind(t_dc_list **node)
{
	while ((*node)->sign != '@')
	{
		(*node) = (*node)->prev;
	}
}
