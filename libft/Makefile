# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 16:44:48 by pleroux           #+#    #+#              #
#    Updated: 2018/01/29 09:22:08 by pleroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR=./src
INC_DIR=./includes
OBJ_DIR=./obj

RAW_SRC		:= $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")
RAW_DIRS	:= $(shell find $(SRC_DIR) -mindepth 1 -type d )
SRCDIRS 	= $(RAW_DIRS:./src/%=%)
SRC			= $(RAW_SRC:./src/%=%)
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC=gcc
NAME=libft.a

VAR_NOT_USED = -Wno-unused-but-set-parameter

CFLAGS		= -Wall -Wextra -Werror -std=c99

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(addprefix $(OBJ_DIR)/,$(SRCDIRS))

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

fclean: clean
	/bin/rm -f $(NAME)

clean:
	/bin/rm -rf $(OBJ_DIR)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all clean fclean re
