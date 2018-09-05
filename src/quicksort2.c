#include "../includes/push_swap.h"

int			sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->val > a->next->val)
			return (1);
		a = a->next;
	}
	return (0);
}

void		quicksort_b(t_stack **a_head, t_stack **b_head)
{
	t_stack *tmp;
	t_stack *a;
	t_stack *b;

	a = *a_head;
	b = *b_head;
	tmp = b;
	if (b->next && b->val > b->next->val)
	{
		ft_putendl("sb");
		b = swap(b);
	}
	ft_putendl("pa");
	b = push(b, &a);
	*a_head = a;
	*b_head = b;
}

void		quicksort3(t_stack *a_head, t_stack *b_head)
{
	t_stack	*b;
	t_stack	*temp;
	int 	i;
	int		sort;
	int		size;

	i = -1;
	temp = b_head;
	b = b_head;
	sort = 0;
	
	t_stack *yy;

	yy = b_head;
	while (yy)
	{
		fprintf(stderr, "%d ", yy->val);
		fflush(stderr);
		yy = yy->next;
		sleep(1);
	}

	size = stack_size(b_head);
	while (++i < size)
	{
		if ((sort == 1 && (b->next == NULL || b->next->sort == 1)) || temp == b || b->sort == 1)
		{
			ft_putendl("pa");
			b = push(b, &a_head);
			sort = 1;
		}
		else
		{
			quicksort_b(&a_head, &b);
			sort = 0;
		}
	}

		fprintf(stderr, "---");
		fflush(stderr);
		t_stack *haha;
		while (haha)
		{
		fprintf(stderr, "%d ", haha->val);
		fflush(stderr);
		haha = haha->next;
			
		}
		fprintf(stderr, "\n");
		fflush(stderr);
	while (sorted(a_head) == 1)
		quicksort2(a_head, b_head, 0);
}

void	quicksort2(t_stack *a_head, t_stack *b_head, int n)
{
	int pivot;
	t_stack *tmp;
	int i;
	int size;
	int size2;

	tmp = a_head;
	size2 = stack_size(a_head);
	
	t_stack *temp;

			temp = b_head;
			if (b_head)
			{
				while (temp)
				{
					fprintf(stderr, "______%d ", temp->val);
					fflush(stderr);
					temp = temp->next;
				}
				fprintf(stderr, "Here\n");
				fflush(stderr);
			}

	while (size2 > 1)
	{
		i = -1;
		pivot = tmp->val;
		tmp->sort = 1;
		size = size2;
		while (++i < size)
		{
			if (tmp->val < pivot)
			{
				tmp = push(tmp, &b_head);
				ft_putendl("pb");
				size2--;
			}
			else
			{
				ft_putendl("ra");
				tmp = rotate(tmp);
			}

			temp = b_head;
			while (temp)
			{
				fprintf(stderr, "%d ", temp->val);
				fflush(stderr);
				temp = temp->next;
			}
			fprintf(stderr, "\n");
			fflush(stderr);

		}
		if (size2 == 1)
			break;
		tmp = push(tmp, &b_head);
		ft_putendl("pb");
		--size2;
	}
	a_head = tmp;
	quicksort3(a_head, b_head);
}
