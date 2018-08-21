/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:39:58 by dpoulter          #+#    #+#             */
/*   Updated: 2018/08/21 11:44:00 by dpoulter         ###   ########.fr       */
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
	struct s_stack	*next;
}				t_stack;

t_stack			*remove_front(t_stack *head);
t_stack			*remove_back(t_stack *head);
t_stack			*create(int data, t_stack *next);
t_stack			*append(t_stack *head, int data);
t_stack			*insert_after(t_stack *head, int data, t_stack *prev);
t_stack			*insert_begin(t_stack *head, int data);
int				stack_size(t_stack *head);
int				median_stack(t_stack *head);

void			error_code(int status);

t_stack			*swap(t_stack *head);
t_stack			*push(t_stack *head, t_stack **dst);
t_stack			*rotate(t_stack *head);
t_stack			*rrotate(t_stack *head);

void			my_basic_algorithm(t_stack **a_head, t_stack **b_head);

#endif
