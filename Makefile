# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gubusque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 00:20:30 by gubusque          #+#    #+#              #
#    Updated: 2025/12/29 01:07:17 by gubusque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Direcotires \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

SRC_DIR		= src/
OBJ_DIR		= obj/
INCLUDE_DIR	= include/
LIBFT_DIR	= libft/
LIBMLX_DIR	= minilibx-linux/

# Files \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

SRC	= main.c	\
	  map_reader.c	\
	  map_printer.c	\
	  key_press.c	\
	  check_exit.c	\
	  pathfinder.c	\
	  ft_free.c	\
	  ft_error.c	\
		
# Objects \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

OBJ	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# Libreries \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

LIBFT	= $(LIBFT_DIR)libft.a
LIBMLX	= $(LIBMLX_DIR)libmlx.a

# Compilate && flags \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS	= -L$(LIBFT_DIR) -lft -L$(LIBMLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDE = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(LIBMLX_DIR)

# Rules \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#

all: libft libmlx $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)


$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft: 
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

libmlx:
	$(MAKE) -C $(LIBMLX_DIR) --no-print-directory

clean:
	$(RM) $(OBJ) $(LIBFT) $(LIBMLX)
	$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	$(MAKE) -C $(LIBMLX_DIR) clean --no-print-directory

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean all

.PHONY: all libft libmlx clean fclean re
