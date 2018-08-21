/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  checker.h                        |_|_| |___                               */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <daniel@poulter.co.za>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:12:23 by dpoulter          #+#    #+#             */
/*  Updated: 2018/08/15 17:25:22 b               |    |  | |  \ |___          */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

# define RED "\x1B[31m"
# define WHITE "\x1B[37m"

typedef struct s_stack{
	int val;
	struct s_stack *next;
}				t_stack;

t_stack		*remove_front(t_stack *head);
t_stack		*remove_back(t_stack *head);
t_stack		*create(int data, t_stack *next);
t_stack		*append(t_stack *head, int data);
t_stack		*insert_after(t_stack *head, int data, t_stack *prev);
t_stack		*insert_begin(t_stack *head, int data);

void		error_code(int status);

t_stack		*swap(t_stack *head);
t_stack		*push(t_stack *head, t_stack **dst);
t_stack		*rotate(t_stack *head);
t_stack		*rrotate(t_stack *head);

#endif
