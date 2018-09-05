/* ************************************************************************** */
/*                                   _ _ _ ____                               */
/*                                   | | | |___                               */
/*  is_sorted.c                      |_|_| |___                               */
/*                                        ___ _  _ _ _  _ _  _                */
/*  By: coding <marvin@42.fr>              |  |__| | |\ | |_/                 */
/*                                         |  |  | | | \| | \_                */
/*  Created: 2018/08/23 12:41:50 b               ____ ____ ___  ____          */
/*  Updated: 2018/08/23 13:28:48 b               |    |  | |  \ |___          */
/*                                               |___ |__| |__/ |___ .co.za   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_sorted(t_stack *a_head)
{
	t_stack *tmp;

	tmp = a_head;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		shortest_path(t_stack **head, int to_find, int stack)
{
	t_stack *tmp;
	t_stack *tmp2;

	tmp = *head;
	tmp2 = *head;
	while (tmp->val != to_find || tmp2->val != to_find)
	{
		tmp = rotate(tmp);
		tmp2 = rrotate(tmp);
	}
	if (tmp->val == to_find)
	{
		if (stack == 1)
			ft_putendl("ra");
		else
			ft_putendl("rb");
		*head = rotate(*head);
	}
	else
	{
		if (stack == 1)
			ft_putendl("rra");
		else
			ft_putendl("rrb");
		*head = rrotate(*head);
	}
}
