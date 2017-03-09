# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eferrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 23:53:10 by eferrand          #+#    #+#              #
#    Updated: 2017/03/09 02:57:55 by eferrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fillit

FILE_LIST	:=	fillitopti.c sup.c
OBJ_FILES	:=	$(FILE_LIST:.c=.o)

LIB_FT		:=	./libft
LIB_FT_INC	:=	-I $(LIB_FT)

LIB_FT_LINK	:=	-l $(LIB_FT)/libft

INCLUDES	:=	$(LIB_FT_INC)
LINK		:=	$(LIB_FT_LINK)

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

all: libs $(NAME)

libs:
	@make -C $(LIB_FT)

$(NAME): $(OBJ_FILES)
	gcc -Wall -Werror -Wextra ./libft/libft.a sup.o fillitopti.o -o fillit

$(OBJ_FILES)/%.o: $(FILE_LIST)
	gcc -Wall -Werror -Wextra -I./libft/ -c sup.c fillitopti.c

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

relibs:
	@make -C $(LIB_FT) re
	@make re --no-print-directory

re: fclean all
