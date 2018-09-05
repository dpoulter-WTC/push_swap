# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 10:08:35 by dpoulter          #+#    #+#              #
#    Updated: 2018/09/05 16:18:02 by dpoulter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

DIR_LIB = libft/

FLAGS = -Wall -Werror -Wextra -g

GCC_HELPER = gcc $(FLAGS)

SRCS := src/checker.c \
		src/list_functions.c \
		src/list_functions2.c \
		src/operations.c \

SRCS2 := src/push_swap.c \
		src/list_functions.c \
		src/list_functions2.c \
		src/operations.c \
		src/quicksort.c \

OBJ = $(SRCS:.c=.o)
OBJ2 = $(SRCS2:.c=.o)

all : $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C libft
	$(GCC_HELPER) $(OBJ) -Iincludes -Ilibft/ -L $(DIR_LIB) -lft -o $(NAME)
	@echo "Checker done"

$(NAME2): $(OBJ2)
	@make -C libft
	$(GCC_HELPER) $(OBJ2) -Iincludes -Ilibft/ -L $(DIR_LIB) -lft -o $(NAME2)
	@echo "Push_swap done"

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@rm -f $(OBJ2)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -f $(NAME2)

re: fclean all
