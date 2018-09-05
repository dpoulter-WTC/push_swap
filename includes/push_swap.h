/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  push_swap.h                      |_|_| |___                               */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:39:58 by dpoulter          #+#    #+#             */
/*  Updated: 2018/09/04 19:29:13 b               |    |  | |  \ |___          */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define RED "\x1B[31m"
# define WHITE "\x1B[37m"

typedef struct	s_stack
{
	int				val;
	int				sort;
	struct s_stack	*next;
}				t_stack;

t_stack			*remove_front(t_stack *head);
t_stack			*remove_back(t_stack *head);
t_stack			*create(int data, t_stack *next);
t_stack			*append(t_stack *head, int data);
t_stack			*insert_after(t_stack *head, int data, t_stack *prev);
t_stack			*insert_begin(t_stack *head, int data);
int				stack_size(t_stack *head);
int				median_stack(t_stack *head, int n);

void			error_code(int status);

t_stack			*swap(t_stack *head);
t_stack			*push(t_stack *head, t_stack **dst);
t_stack			*rotate(t_stack *head);
t_stack			*rrotate(t_stack *head);

void			my_basic_algorithm(t_stack **a_head, t_stack **b_head, int i, int median);

void			quicksort(t_stack ***head, int size, int pile, int n);
void			do_function(t_stack **a_head, t_stack **b_head, char *line);

#endif
