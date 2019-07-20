# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2019/07/20 21:14:13 by pleroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

DBG=-ggdb -fsanitize=address -fno-omit-frame-pointer -g3
DBG2=-ggdb  -fsanitize=address -fsanitize-memory-track-origins

NAME = libft_malloc_$(HOSTTYPE).so
NAME_LN = libft_malloc.so
CC = gcc
LIB_PRINTF = ft_printf/libftprintf.a
LIB_PRINTF_PATH = ft_printf/
LIB_PRINTF_HEADER = ft_printf/inc
LIB_PRINTF_LINK = ftprintf
LIB = libft/libft.a
LIB_PATH = libft/
LIB_HEADER = libft/includes
LIB_LINK = ft
SRC_DIR = src/
INC_DIR = inc/
CFLAGS = -Wall -Werror -Wextra -I $(LIB_HEADER) -I $(LIB_PRINTF_HEADER) -I $(INC_DIR)
LIB_FLAGS = -lncurses -L$(LIB_PRINTF_PATH) -l$(LIB_PRINTF_LINK) -L$(LIB_PATH) -l$(LIB_LINK)
			
INC_FILE = malloc.h \

SRC_FILE = malloc.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
INC = $(addprefix $(INC_DIR), $(INC_FILE))
OBJ = $(SRC:.c=.o)

all		: $(LIB) $(LIB_PRINTF) $(NAME)

$(LIB)	:
	make -C $(LIB_PATH)

$(LIB_PRINTF)	:
	make -C $(LIB_PRINTF_PATH)

%.o: %.c $(INC)
	     $(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	: $(OBJ)
	$(CC) -shared -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_FLAGS)
	ln -s -f $(NAME) $(NAME_LN)

clean	:
	rm -f $(NAME_LN)
	rm -f $(NAME)
	rm -f $(OBJ)
	make -C $(LIB_PATH) fclean
	make -C $(LIB_PRINTF_PATH) fclean

fclean	: clean
	rm -f $(NAME_LN)
	rm -f $(NAME)

re		: clean all

.PHONY	: all clean re fclean $(LIB) $(LIB_PRINTF)
