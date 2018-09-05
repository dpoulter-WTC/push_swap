/* ************************************************************************** */
/*                                   _ _ _ ____                               */
/*                                   | | | |___                               */
/*  algo_quicksort_a.c               |_|_| |___                               */
/*                                        ___ _  _ _ _  _ _  _                */
/*  By: coding <marvin@42.fr>              |  |__| | |\ | |_/                 */
/*                                         |  |  | | | \| | \_                */
/*  Created: 2018/08/23 13:03:24 b               ____ ____ ___  ____          */
/*  Updated: 2018/08/25 10:35:50 b               |    |  | |  \ |___          */
/*                                               |___ |__| |__/ |___ .co.za   */
/* ************************************************************************** */

int			ft_left(t_stack *left, int pivot)
{
	t_stack *temp;

	temp = left;
	while (temp)
	{
		if (temp->val < pivot)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void		ft_push_lower(t_stack **a, t_stack **b, int pivot)
{
	int		step;
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->val < pivot)
		{
			
		}
	}
	else
	{
		ft_exec_rra();
		while (TOP_A != *left)
		{
			if (DATA(TOP_A) < *pivot)
			{
				ft_exec_pb();
				++*pushed;
			}
			ft_exec_rra();
		}
	}
	ft_exec_pb();
	++*pushed;
}

void		ft_ps_quick_a(t_stack *a)
{
	int		pivot;
	int		pushed;
	t_stack	*left;

	pushed = 0;
	while (stack_size(a) > 1)
	{
		pivot = a->next->val;
		if (ft_left(a, pivot))
		{
			ft_push_lower(&left, &pushed, &pivot);
			if (ft_exec_head_is_sorted())
			{
				ft_ps_find_shortest_path(&HEAD_A, DATA(HEAD_A.next));
				break ;
			}
		}
		else
			ft_stack_a_routine(&pushed, &pivot);
	}
}
