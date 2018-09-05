/* ************************************************************************** */
/*                                   _ _ _ ____                               */
/*                                   | | | |___                               */
/*  quicksort.c                      |_|_| |___                               */
/*                                        ___ _  _ _ _  _ _  _                */
/*  By: coding <marvin@42.fr>              |  |__| | |\ | |_/                 */
/*                                         |  |  | | | \| | \_                */
/*  Created: 2018/08/16 14:06:38 b               ____ ____ ___  ____          */
/*  Updated: 2018/09/05 11:08:50 b               |    |  | |  \ |___          */
/*                                               |___ |__| |__/ |___ .co.za   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				iss_sorted(t_stack *main, int size, int pile)
{
	t_stack *cur;
	int		i;

	i = 1;
	cur = main;
	while (cur->next && ((pile && cur->val < cur->next->val) ||
				(!pile && cur->val > cur->next->val)))
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

int				is_sorted(t_stack *main, int size, int pile)
{
	t_stack *cur;
	int		i;

	i = 1;
	cur = main;
	while (cur->next && ((pile && cur->val < cur->next->val) ||
				(!pile && cur->val > cur->next->val)))
	{
		i++;
		cur = cur->next;
	}
	return (i >= size);
}

void		sort3(t_stack **a_head, t_stack **b_head, int size, int pile)
{
	if (!is_sorted((pile) ? (*a_head) : (*b_head), size, pile))
	{
		if (!is_sorted((pile) ? *(a_head) : *(b_head), 2, pile))
		{
			if (pile)
			{
				(*a_head) = swap((*a_head));
				ft_putendl("sa");
			}
			else
			{
				(*b_head) = swap((*b_head));
				ft_putendl("sb");
			}
		}
		else
		{
			if (pile)
			{
				(*a_head) = rotate((*a_head));
				ft_putendl("ra");
				(*a_head) = swap((*a_head));
				ft_putendl("sa");
				(*a_head) = rrotate((*a_head));
				ft_putendl("rra");
			}
			else
			{
				(*b_head) = rotate((*b_head));
				ft_putendl("rb");
				(*b_head) = swap((*b_head));
				ft_putendl("sb");
				(*b_head) = rrotate((*b_head));
				ft_putendl("rrb");
			}
		}
		sort3(a_head, b_head, size, pile);
	}
}

int			pusher(t_stack **a_head, t_stack **b_head, int pile, int pivot)
{
	if ((pile && (*a_head)->val < pivot) || (!pile && (*b_head)->val >= pivot))
	{
		if (!pile)
		{
			(*b_head) = push((*b_head), a_head);
			ft_putendl("pa");
		}
		else
		{
			(*a_head) = push((*a_head), b_head);
			ft_putendl("pb");
		}
		return (1);
	}
	else
	{
		if (!pile)
		{
			(*b_head) = rotate((*b_head));
			ft_putendl("rb");
		}
		else
		{
			(*a_head) = rotate((*a_head));
			ft_putendl("ra");
		}
	}
	return (0);
}

int			median(t_stack *stack, int size)
{
	int		larger;
	int		lower;
	int		i;
	t_stack	*cur;
	t_stack	*tmp;

	cur = stack;
	larger = 0;
	lower = 2;
	while (larger - lower != 0 && larger - lower != -1)
	{
		larger = 0;
		lower = 0;
		i = -1;
		tmp = stack;
		while (++i < size)
		{
			larger += (cur->val < tmp->val);
			lower += (cur->val > tmp->val);
			tmp = tmp->next;
		}
		tmp = cur; 
		cur = cur->next;
	}
	return (tmp->val);
}

void		quicksort(t_stack **a_head, t_stack **b_head, int size, int pile, int n)
{
	int i;
	int pivot;
	int reset;

	reset = 0;
	i = 0;
	pivot = median((pile) ? *(a_head) : *(b_head), size);
	if (is_sorted((pile) ? *(a_head) : *(b_head), size, pile))
		return ;
	while (size > 3 && i < (size / 2) + (size % 2 && !pile) && ++reset)
		i += pusher(a_head, b_head, pile, pivot);
	while ((!n) && (reset--) - i)
	{
		if (!pile)
		{
			(*b_head) = rrotate((*b_head));
			ft_putendl("rrb");
		}
		else
		{
			(*a_head) = rrotate((*a_head));
			ft_putendl("rra");
		}
	}
	if (i && !pile)
		quicksort(&(*a_head), &(*b_head), i, !pile, 0);
	if (size - i <= 3)
		sort3(&(*a_head), &(*b_head), size - i, pile);
	else
		quicksort(&(*a_head), &(*b_head), size - i, pile, (n == 2) ? n - 1 : n);
	if (i && pile)
		quicksort(&(*a_head), &(*b_head), i, !pile, (n == 2) ? 1: 0);
	while (i--)
	{
		if (pile)
		{
			(*b_head) = push((*b_head), a_head);
			ft_putendl("pa");
		}
		else
		{
			(*a_head) = push((*a_head), b_head);
			ft_putendl("pb");
		}
	}
}
