/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:29:04 by dpoulter          #+#    #+#             */
/*   Updated: 2018/09/05 15:17:16 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_sorted(t_stack *main, int size, int pile)
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
			do_function(&(*a_head), &(*b_head), (pile) ? "sa" : "sb");
		else
		{
			if (pile)
			{
				do_function(&(*a_head), &(*b_head), "ra");
				do_function(&(*a_head), &(*b_head), "sa");
				do_function(&(*a_head), &(*b_head), "rra");
			}
			else
			{
				do_function(&(*a_head), &(*b_head), "rb");
				do_function(&(*a_head), &(*b_head), "sb");
				do_function(&(*a_head), &(*b_head), "rrb");
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
			do_function(&(*a_head), &(*b_head), "pa");
		else
			do_function(&(*a_head), &(*b_head), "pb");
		return (1);
	}
	else
	{
		if (!pile)
			do_function(&(*a_head), &(*b_head), "rb");
		else
			do_function(&(*a_head), &(*b_head), "ra");
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

void		quicksort(t_stack ***head, int size, int pile, int n)
{
	int i;
	int pivot;
	int reset;

	reset = 0;
	i = 0;
	pivot = median((pile) ? *(head[0]) : *(head[1]), size);
	if (is_sorted((pile) ? *(head[0]) : *(head[1]), size, pile))
		return ;
	while (size > 3 && i < (size / 2) + (size % 2 && !pile) && ++reset)
		i += pusher(head[0], head[1], pile, pivot);
	while ((!n) && (reset--) - i)
		do_function(&(*head[0]), &(*head[1]), (!pile) ? "rrb" : "rra");
	if (i && !pile)
		quicksort(&(*head), i, !pile, 0);
	if (size - i <= 3)
		sort3(&(*head[0]), &(*head[1]), size - i, pile);
	else
		quicksort(&(*head), size - i, pile, (n == 2) ? n - 1 : n);
	if (i && pile)
		quicksort(&(*head), i, !pile, (n == 2) ? 1 : 0);
	while (i--)
		do_function(&(*head[0]), &(*head[1]), (pile) ? "pa" : "pb");
}
