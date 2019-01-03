# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/29 17:05:03 by lreznak-          #+#    #+#              #
#    Updated: 2019/01/03 03:49:32 by lreznak-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
SRC		= src
INC		= -Iinclude
OBJ		= object
EXE		= exe
GNL		= get_next_line
LFT		= libft

all: $(NAME)

$(NAME):
	@cd $(LFT) && make && cd -
	@gcc -Wall -Wextra -Werror \
	$(INC) $(SRC)/fillit.c $(SRC)/figure_handle.c $(SRC)/val_one_figure.c \
	$(SRC)/dcl_add.c $(SRC)/dcl_new.c $(SRC)/figure_create.c \
	$(SRC)/cutter.c $(SRC)/filler.c $(SRC)/map.c $(SRC)/val.c $(SRC)/dcl_rewind.c $(SRC)/min_sz.c \
	$(SRC)/map_eraser.c \
	$(LFT)/libft.a \
	-o $(NAME)
	@echo COMPILED!

clean:
	@cd $(LFT) && make fclean && cd -

fclean: clean
	rm -rf fillit

re: fclean all
