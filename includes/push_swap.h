/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:20:24 by dpoulter          #+#    #+#             */
/*   Updated: 2018/09/06 13:26:31 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define RED "\x1B[31m"
# define WHITE "\x1B[37m"
# define MAX_INT 2147483647

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
void			check_dupe(t_stack *head);

t_stack			*swap(t_stack *head);
t_stack			*push(t_stack *head, t_stack **dst);
t_stack			*rotate(t_stack *head);
t_stack			*rrotate(t_stack *head);

void			quicksort(t_stack ***head, int size, int pile, int n);
void			do_function(t_stack **a_head, t_stack **b_head, char *line);

#endif
