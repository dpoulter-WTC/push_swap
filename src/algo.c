/* ************************************************************************** */
/*                                   _ _ _ ____                               */
/*                                   | | | |___                               */
/*  algo.c                           |_|_| |___                               */
/*                                        ___ _  _ _ _  _ _  _                */
/*  By: coding <marvin@42.fr>              |  |__| | |\ | |_/                 */
/*                                         |  |  | | | \| | \_                */
/*  Created: 2018/08/20 18:54:11 b               ____ ____ ___  ____          */
/*  Updated: 2018/08/20 20:29:28 b               |    |  | |  \ |___          */
/*                                               |___ |__| |__/ |___ .co.za   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sort_list_nb(t_stack *a_head, t_stack *b_head)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = a_head;
	if (b_head != NULL)
		i = 1;
	while (temp != NULL && temp->next != NULL && i <= 1)
	{
		if (temp->val > temp->next->val)
			i = 2;
		temp = temp->next;
	}
	return (i);
}

int		check_nb(t_stack *list)
{
	t_stack	*tmp;

	if (list == NULL)
		return (1);
	tmp = list;
	if (tmp->val > tmp->next->val)
		return (1);
	return (0);
}

void		my_basic_algorithm(t_stack **a_head, t_stack **b_head)
{
	if (sort_list_nb(*a_head, *b_head) != 0)
	{
		if (((*a_head) && (*a_head)->next) && (check_nb(*a_head) == 1))
		{
			*a_head = swap(*a_head);
			ft_putendl("sa");
		}
		else
		{
			*a_head = push(*a_head, b_head);
			ft_putendl("pb");
		}
	}
	while (sort_list_nb(*a_head, *b_head) != 0)
	{
		if (sort_list_nb(*a_head, *b_head) == 2)
		{
			if (((*a_head) && (*a_head)->next) && (check_nb(*a_head) == 1))
			{
				*a_head = swap(*a_head);
				ft_putendl("sa");
			}
			else
			{
				*a_head = push(*a_head, b_head);
				ft_putendl("pb");
			}
		}
		else
		{
			if (((*b_head) && (*a_head) && (*b_head)->next) && (check_nb(*b_head) == 0))
			{
				*b_head = swap(*b_head);
				ft_putendl("sb");
			}
			*b_head = push(*b_head, a_head);
			ft_putendl("pa");
		}
	}
}
