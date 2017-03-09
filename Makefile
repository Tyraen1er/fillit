# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eferrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 23:53:10 by eferrand          #+#    #+#              #
#    Updated: 2017/03/09 03:09:58 by eferrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fillit

FILE_LIST	:=	fillitopti.c sup.c
OBJ_FILES	:=	$(FILE_LIST:.c=.o)

LIB_FT		:=	./libft
LIB_FT_INC	:=	-I $(LIB_FT)

LIB_FT_LINK	:=	$(LIB_FT)/libft.a

INCLUDES	:=	$(LIB_FT_INC)
LINK		:=	$(LIB_FT_LINK)

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

all: libs $(NAME)

libs:
	@make -C $(LIB_FT)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LINK) $(OBJ_FILES) -o $(NAME)

$(OBJ_FILES)/%.o: $(FILE_LIST)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(FILE_LIST)

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

relibs:
	@make -C $(LIB_FT) re
	@make re --no-print-directory

re: fclean all
