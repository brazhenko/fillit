# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/29 17:05:03 by lreznak-          #+#    #+#              #
#    Updated: 2018/12/31 10:31:41 by hharrold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
SRC		= src
INC		= -Iinclude
OBJ		= object
EXE		= exe
GNL		= get_next_line
LFT		= $(GNL)/libft
all:
	@cd get_next_line/libft && make && cd ../..
	@gcc  \
	$(INC) $(SRC)/fillit.c $(SRC)/figure_handle.c $(SRC)/val_one_figure.c \
	$(SRC)/dcl_add.c $(SRC)/dcl_new.c $(SRC)/figure_create.c $(SRC)/testlist.c \
	$(SRC)/cutter.c $(SRC)/filler.c $(SRC)/map.c $(SRC)/val.c $(SRC)/dcl_rewind.c \
	$(GNL)/get_next_line.c $(LFT)/libft.a \
	-o fillit
	@echo COMPILED!
