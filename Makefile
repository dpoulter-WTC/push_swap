# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 10:08:35 by dpoulter          #+#    #+#              #
#    Updated: 2018/08/01 00:50:56 by dpoulter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

FLAGS = -Wall -Werror -Wextra -I./includes

SRCS := src/checker.c \
		src/list_functions.c \
		src/operations.c \

SRCS2 := src/push_swap.c \
		src/list_functions.c \
		src/operations.c \
		src/algo.c \

OBJ = $(SRCS:.c=.o)
OBJ2 = $(SRCS2:.c=.o)

all : $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C libft
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@echo "Checker done"

$(NAME2): $(OBJ2)
	@make -C libft
	@gcc -o $(NAME2) $(FLAGS) $(OBJ2) libft/libft.a
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
