/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:20:16 by dpoulter          #+#    #+#             */
/*   Updated: 2018/09/06 13:20:18 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

# define RED "\x1B[31m"
# define WHITE "\x1B[37m"
# define MAX_INT 2147483647

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

void			error_code(int status);
void			recieve(t_stack **a_head, t_stack **b_head, char *line);
void			check_dupe(t_stack *head);

t_stack			*swap(t_stack *head);
t_stack			*push(t_stack *head, t_stack **dst);
t_stack			*rotate(t_stack *head);
t_stack			*rrotate(t_stack *head);

#endif
