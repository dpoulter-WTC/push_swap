/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:56:40 by dpoulter          #+#    #+#             */
/*   Updated: 2018/08/21 11:59:04 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_code(int status)
{
	ft_putstr_fd(RED, 2);
	if (status == 0)
		ft_putstr_fd("Error: Incorrect usage of ./push_swap\n", 2);
	ft_putstr_fd(WHITE, 2);
	exit(1);
}

void	populate(char **argv, int argc, t_stack *a_head)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		split = ft_strsplit(argv[i], ' ');
		while (split[++j])
		{
			a_head = append(a_head, ft_atoi(split[j]));
		}
	}
}

int		median_stack(t_stack *head)
{
	int temp;
	int size;
	int i;
	int *arr;
	int j;

	size = stack_size(head);
	arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (head)
	{
		arr[i] = head->val;
		i++;
		head = head->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	}
	if (size % 2 == 0)
		return ((arr[size / 2] + arr[size / 2 - 1]) / 2);
	else
		return (arr[size / 2]);
}

int		main(int argc, char **argv)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack	*a;
	int		high;

	if (argc == 1)
		error_code(0);
	a_head = create(-3, NULL);
	populate(argv, argc, a_head);
	a_head = remove_front(a_head);
	a = a_head;
	high = 1;
	while (a->next)
	{
		high++;
		a = a->next;
	}
	my_basic_algorithm(&a_head, &b_head);
	return (0);
}
