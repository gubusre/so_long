# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gubusque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 20:12:58 by gubusque          #+#    #+#              #
#    Updated: 2025/12/21 16:42:29 by gubusque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_DIR = obj/

SRC = \
	ft_calloc.c ft_isascii.c ft_itoa.c ft_memcmp.c ft_memset.c \
	ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c \
	ft_substr.c ft_atoi.c ft_isalnum.c ft_isdigit.c	ft_memcpy.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c \
	ft_strrchr.c ft_tolower.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memchr.c \
	ft_memmove.c ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c \
	ft_strncmp.c ft_strtrim.c ft_toupper.c	\
	ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
	ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c\
	ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c \
	get_next_line.c	\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INCLUDE = libft.h

CC = cc
CCFLAGS = -Wall -Wextra -Werror

LIB = ar rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean all

.PHONY: all bonus clean fclean re rebonus
