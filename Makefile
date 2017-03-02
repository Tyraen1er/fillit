# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eferrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 23:53:10 by eferrand          #+#    #+#              #
#    Updated: 2017/03/02 07:29:50 by eferrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fillit

SRC_DIR		:=	./src
INC_DIR		:=	./includes
LIB_DIR		:=	./lib
OBJ_DIR		:=	./obj

FILE_LIST	:=	fillitopti.c sup.c
OBJ_FILES	:=	$(addprefix $(OBJ_DIR)/,$(FILE_LIST:.c=.o))

LIB_FT		:=	$(LIB_DIR)/libft
LIB_FT_INC	:=	-I $(LIB_FT)/includes

LIB_FT_LINK	:=	-L $(LIB_FT) -l ft

INCLUDES	:=	$(LIB_FT_INC) -I $(INC_DIR)
LINK		:=	$(LIB_FT_LINK)

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -g

all: obj libs $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

libs:
	@make -C $(LIB_FT)

$(NAME): $(OBJ_FILES)
	$(CC) $(LINK) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

relibs:
	@make -C $(LIB_FT) re
	@make re --no-print-directory

re: fclean all
