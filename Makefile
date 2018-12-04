# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 10:08:35 by dpoulter          #+#    #+#              #
#    Updated: 2018/09/06 13:25:57 by dpoulter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap
SRCS1 := src/checker.c \
		src/checker2.c \
		src/list_functions.c \
		src/list_functions2.c \
		src/operations.c \

SRCS2 := src/push_swap.c \
		src/checker2.c \
		src/list_functions.c \
		src/list_functions2.c \
		src/operations.c \
		src/quicksort.c \

SRCS3 = $(wildcard $(SRCS1))
SRCS4 = $(wildcard $(SRCS2))
BINS1 = $(patsubst src/%.c, %.o, $(SRCS3))
BINS2 = $(patsubst src/%.c, %.o, $(SRCS4))
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

.PHONY: all clean fclean

%.o : libft/src/%.c
	gcc -Ilibft/includes $(FLAGS) -c $<

%.o : src/%.c
	gcc -Iincludes -Ilibft/includes $(FLAGS) -c $<

all: libft $(NAME1) $(NAME2)

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME1): $(LIBFT) $(BINS)
	gcc -Iincludes -Ilibft/includes $(FLAGS) $(LIBFT) $(SRCS3) -o $(NAME1)

$(NAME2): $(LIBFT) $(BINS)
	gcc -Iincludes -Ilibft/includes $(FLAGS) $(LIBFT) $(SRCS4) -o $(NAME2)

clean:
	make clean -C ./libft
	/bin/rm -f $(BINS1)
	/bin/rm -f $(BINS2)

fclean: clean
	make fclean -C ./libft
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)

re: fclean all
