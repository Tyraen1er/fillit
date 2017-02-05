# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eferrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 22:08:18 by eferrand          #+#    #+#              #
#    Updated: 2017/01/31 22:02:12 by eferrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a

SRC_DIR		:=	./src
OBJ_DIR		:=	./obj
INC_DIR		:=	./includes

FILE_LIST	:=	ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memccpy.c	\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_strdup.c		\
				ft_strcpy.c		\
				ft_strncpy.c	\
				ft_strcat.c		\
				ft_strncat.c	\
				ft_strlcat.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strstr.c		\
				ft_strnstr.c	\
				ft_strcmp.c		\
				ft_strncmp.c	\
				ft_atoi.c		\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_memalloc.c	\
				ft_memdel.c		\
				ft_strnew.c		\
				ft_strdel.c		\
				ft_strclr.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strmap.c		\
				ft_strmapi.c	\
				ft_strequ.c		\
				ft_strnequ.c	\
				ft_strsub.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_strsplit.c	\
				ft_itoa.c		\
				ft_putchar.c	\
				ft_putstr.c		\
				ft_putendl.c	\
				ft_putnbr.c		\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_lstnew.c		\
				ft_lstdelone.c	\
				ft_lstdel.c		\
				ft_lstadd.c		\
				ft_lstiter.c	\
				ft_lstmap.c		\
				ft_realloc.c	\
				ft_power.c		\
				ft_root.c

OBJ_FILES	:=	$(addprefix $(OBJ_DIR)/,$(FILE_LIST:.c=.o))
INCLUDES	:=	-I $(INC_DIR)
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

all: obj $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
