/* ************************************************************************** */
/*                                   _ _ _ ____                               */
/*                                   | | | |___                               */
/*  quickalgo.c                      |_|_| |___                               */
/*                                        ___ _  _ _ _  _ _  _                */
/*  By: coding <marvin@42.fr>              |  |__| | |\ | |_/                 */
/*                                         |  |  | | | \| | \_                */
/*  Created: 2018/09/03 11:46:46 b               ____ ____ ___  ____          */
/*  Updated: 2018/09/03 19:02:25 b               |    |  | |  \ |___          */
/*                                               |___ |__| |__/ |___ .co.za   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			issorted(t_stack *a)
{
	while (a->next)
	{
		if (a->val > a->next->val)
			return (1);
		a = a->next;
	}
	return (0);
}

int		biggest(t_stack *a)
{
	int i;
	
	i = 0;
	while (a)
	{
		if (a->val > i)
			i = a->val;
		a = a->next;
	}
	return (i);
}

void		merge(t_stack *a_head, t_stack *b_head, int median)
{
	int size;
	int counter;
	t_stack *tmp;

	size = stack_size(a_head);
	counter = -1;
	while (++counter < size)
	{
		if (a_head->val > median)
		{
			a_head = push(a_head, &b_head);
			ft_putendl("pb");
		}
		else
		{
			a_head = rotate(a_head);
			ft_putendl("ra");
		}
	}
	size = stack_size(a_head);
	while (issorted(a_head)  || issorted(b_head))
	{
		counter = -1;
		if (a_head->val == biggest(a_head))
		{
			if (b_head->val == biggest(b_head))
			{
				a_head = rotate(a_head);
				b_head = rotate(b_head);
				ft_putendl("rr");
			}
			else
			{
				a_head = rotate(a_head);
				ft_putendl("ra");
			}
		}
		if (b_head->val == biggest(b_head))
		{
			b_head = rotate(b_head);
			ft_putendl("rb");
		}
			if (a_head->next && (a_head->val > a_head->next->val))
			{	
				if (b_head->next && (b_head->val > b_head->next->val))
				{
					a_head = swap(a_head);
					b_head = swap(b_head);
					ft_putendl("ss");			
				}
				else
				{
					a_head = swap(a_head);
					ft_putendl("sa");
				}
			}
			else if (b_head->next && b_head->val > b_head->next->val)
			{
				b_head = swap(b_head);
				ft_putendl("sb");
			}
			if (issorted(a_head) && issorted(b_head))
			{
				a_head = rotate(a_head);
				b_head = rotate(b_head);
				ft_putendl("rr");
			}
			else if (issorted(b_head) && !issorted(a_head))
			{
				a_head = rotate(a_head);
				ft_putendl("ra");
			}
			else if (issorted(a_head) && !issorted(b_head))
			{
				b_head = rotate(b_head);
				ft_putendl("rb");
			}

	}

			while (b_head)
			{
				b_head = push(b_head, &a_head);
				ft_putendl("pa");
				a_head = rotate(a_head);
				ft_putendl("ra");
			}
}
