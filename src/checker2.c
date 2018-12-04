/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:33:16 by dpoulter          #+#    #+#             */
/*   Updated: 2018/09/06 13:19:17 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	compare(char *line, t_stack **a_head, t_stack **b_head)
{
	if (ft_strcmp(line, "") == 0)
		ft_putendl_fd("Please input a command", 2);
	else if (ft_strcmp(line, "pa") == 0)
		*b_head = push(*b_head, &(*a_head));
	else if (ft_strcmp(line, "pb") == 0)
		*a_head = push(*a_head, &(*b_head));
	else if (ft_strcmp(line, "ra") == 0)
		*a_head = rotate(*a_head);
	else if (ft_strcmp(line, "rb") == 0)
		*b_head = rotate(*b_head);
	else if (ft_strcmp(line, "sa") == 0)
		*a_head = swap(*a_head);
	else if (ft_strcmp(line, "sb") == 0)
		*b_head = swap(*b_head);
	else if (ft_strcmp(line, "rr") == 0)
	{
		*a_head = rotate(*a_head);
		*b_head = rotate(*b_head);
	}
	else if (ft_strcmp(line, "rra") == 0)
		*a_head = rrotate(*a_head);
	else if (ft_strcmp(line, "rrb") == 0)
		*b_head = rrotate(*b_head);
	else
		error_code(5);
}

void	recieve(t_stack **a_head, t_stack **b_head, char *line)
{
	if (ft_strcmp(line, "ss") == 0)
	{
		*a_head = swap(*a_head);
		*b_head = swap(*b_head);
	}
	else if (ft_strcmp(line, "rrr") == 0)
	{
		*a_head = rrotate(*a_head);
		*b_head = rrotate(*b_head);
	}
	else
		compare(line, &(*a_head), &(*b_head));
}

void	check_dupe(t_stack *head)
{
	t_stack *loop;
	t_stack *curr;

	curr = head;
	while (curr->next)
	{
		loop = curr->next;
		while (loop)
		{
			if (curr->val == loop->val)
				error_code(3);
			loop = loop->next;
		}
		curr = curr->next;
	}
}
