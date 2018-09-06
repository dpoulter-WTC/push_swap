/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:14:27 by dpoulter          #+#    #+#             */
/*   Updated: 2018/09/06 12:14:29 by dpoulter         ###   ########.fr       */
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
			ft_strdel(&split[j]);
		}
		free(split);
	}
}

void	do_function(t_stack **a_head, t_stack **b_head, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		*a_head = swap(*a_head);
	if (ft_strcmp(line, "sb") == 0)
		*b_head = swap(*b_head);
	if (ft_strcmp(line, "pa") == 0)
		*b_head = push(*b_head, &(*a_head));
	if (ft_strcmp(line, "pb") == 0)
		*a_head = push(*a_head, &(*b_head));
	if (ft_strcmp(line, "ra") == 0)
		*a_head = rotate(*a_head);
	if (ft_strcmp(line, "rb") == 0)
		*b_head = rotate(*b_head);
	if (ft_strcmp(line, "rra") == 0)
		*a_head = rrotate(*a_head);
	if (ft_strcmp(line, "rrb") == 0)
		*b_head = rrotate(*b_head);
	ft_putendl(line);
}

int		main(int argc, char **argv)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack	***head;

	if (argc == 1)
		error_code(0);
	a_head = create(-3, NULL);
	populate(argv, argc, a_head);
	a_head = remove_front(a_head);
	head = (t_stack ***)malloc(sizeof(t_stack **) * 2);
	head[0] = &a_head;
	head[1] = &b_head;
	quicksort(head, stack_size(a_head), 1, 2);
	free(head);
	return (0);
}
