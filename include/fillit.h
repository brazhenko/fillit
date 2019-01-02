/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 01:35:49 by hharrold          #+#    #+#             */
/*   Updated: 2019/01/02 06:18:18 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "get_next_line.h"
# include <fcntl.h>

typedef struct				s_dc_list
{
	struct s_dc_list	*next;
	struct s_dc_list	*prev;
	char				sign;
	char				**figure;
}							t_dc_list;

int							min_sz(int f_c);
int							val_one_figure(char **fig);
int							check_n_fill(int fd, t_dc_list **node);
char						**map_gen(void);
int							val_map(char **map, int size);
char						**map_gen(void);
char						**figure_create(char *line);
void						dcl_add(t_dc_list **old, t_dc_list *new);
t_dc_list					*dcl_new(char **str);
void						forward_printer(t_dc_list **fig);
char						**cutter(char* str, int f_c);
void						filler(int f_c, int sz, t_dc_list *node);
void						dcl_rewind(t_dc_list **node);
void						map_eraser(char ***map, char sign, int sz);

#endif
