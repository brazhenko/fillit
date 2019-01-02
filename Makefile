# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/29 17:05:03 by lreznak-          #+#    #+#              #
#    Updated: 2019/01/02 08:56:42 by lreznak-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
SRC		= src
INC		= -Iinclude
OBJ		= object
EXE		= exe
GNL		= get_next_line
LFT		= $(GNL)/libft

all: $(NAME)

$(NAME):
	@cd get_next_line/libft && make && cd ../..
	@gcc -Og -Wall -Wextra -Werror \
	$(INC) $(SRC)/fillit.c $(SRC)/figure_handle.c $(SRC)/val_one_figure.c \
	$(SRC)/dcl_add.c $(SRC)/dcl_new.c $(SRC)/figure_create.c $(SRC)/forward_printer.c \
	$(SRC)/cutter.c $(SRC)/filler.c $(SRC)/map.c $(SRC)/val.c $(SRC)/dcl_rewind.c $(SRC)/min_sz.c \
	$(SRC)/map_eraser.c \
	$(GNL)/get_next_line.c $(LFT)/libft.a \
	-o $(NAME)
	@echo COMPILED!

clean:
	@cd $(LFT) && make fclean && cd -

fclean: clean
	rm -rf fillit

re: fclean all
