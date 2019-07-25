# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2019/07/25 11:34:46 by pleroux          ###   ########.fr        #
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
CFLAGS = -Wall -Werror -Wextra -g
INCL = -I $(LIB_HEADER) -I $(LIB_PRINTF_HEADER) -I $(INC_DIR)
LD_FLAGS = -shared
LIB_FLAGS = -L$(LIB_PRINTF_PATH) -l$(LIB_PRINTF_LINK) -L$(LIB_PATH) -l$(LIB_LINK)

TEST_PATH = test/
TEST = main.test.c
			
INC_FILE = malloc.h \

SRC_FILE = malloc.c \
			free.c \
			linked.c \
			page.c \
			realloc.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
INC = $(addprefix $(INC_DIR), $(INC_FILE))
OBJ = $(SRC:.c=.o)

all		: $(LIB) $(LIB_PRINTF) $(NAME)

$(LIB)	:
	make -C $(LIB_PATH)

$(LIB_PRINTF)	:
	make -C $(LIB_PRINTF_PATH)

%.o: %.c $(INC)
	     $(CC) $(CFLAGS) $(INCL) -o $@ -c $<

$(NAME)	: $(OBJ)
	$(CC) $(LD_FLAGS) $(LIB_FLAGS) $(INCL) -o $(NAME) $(OBJ)
	ln -s -f $(NAME) $(NAME_LN)

clean	:
	rm -f $(OBJ)
	make -C $(LIB_PATH) clean
	make -C $(LIB_PRINTF_PATH) clean

fclean	: clean
	rm -f $(NAME_LN)
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean
	make -C $(LIB_PRINTF_PATH) fclean

re		: fclean all

test	: $(NAME)
	$(CC) $(LIB_FLAGS) $(INCL) $(TEST_PATH)$(TEST) -L. -lft_malloc -o $(TEST_PATH)test
	$(CC) $(LIB_FLAGS) $(INCL) $(TEST_PATH)test0.c -o $(TEST_PATH)test0
	./run.sh time -l test/test0
	./run.sh time -l test/test

.PHONY	: all clean re fclean test $(LIB) $(LIB_PRINTF)
