/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  checker.c                        |_|_| |___                               */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:54:52 by dpoulter          #+#    #+#             */
/*  Updated: 2018/09/05 17:28:09 b               |    |  | |  \ |___          */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	check_sorted(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (b != NULL)
	{
		ft_putstr_fd("\e[1;32mKO\n\e[1;0m", 2);
		return ;
	}
	while (a->next)
	{
		if (a->val > a->next->val)
		{
			i = 1;
		}
		a = a->next;
	}
	if (i != 0)
		ft_putstr_fd("\e[1;34mKO\n", 2);
	else
		ft_putstr_fd("\e[1;33mOK\n", 2);
	ft_putstr_fd("\e[1;0m", 2);
}

void	error_code(int status)
{
	ft_putstr_fd(RED, 2);
	if (status == 0)
		ft_putstr_fd("Error: Arguments incorrect\n", 2);
	if (status == 1)
		ft_putstr_fd("Error: Could not create stack\n", 2);
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

void	compare(char *line, t_stack **a_head, t_stack **b_head)
{
	if (ft_strcmp(line, "pa") == 0)
		*b_head = push(*b_head, &(*a_head));
	if (ft_strcmp(line, "pb") == 0)
		*a_head = push(*a_head, &(*b_head));
	if (ft_strcmp(line, "ra") == 0)
		*a_head = rotate(*a_head);
	if (ft_strcmp(line, "rb") == 0)
		*b_head = rotate(*b_head);
	if (ft_strcmp(line, "rr") == 0)
	{
		*a_head = rotate(*a_head);
		*b_head = rotate(*b_head);
	}
	if (ft_strcmp(line, "rra") == 0)
		*a_head = rrotate(*a_head);
	if (ft_strcmp(line, "rrb") == 0)
		*b_head = rrotate(*b_head);
	if (ft_strcmp(line, "rrr") == 0)
	{
		*a_head = rrotate(*a_head);
		*b_head = rrotate(*b_head);
	}
}

int		main(int argc, char **argv)
{
	char	*line;
	t_stack	*a_head;
	t_stack	*b_head;

	if (argc == 1)
		error_code(0);
	a_head = create(-3, NULL);
	populate(argv, argc, a_head);
	a_head = remove_front(a_head);
	while (ft_gnl(0, &line))
	{
		if (ft_strcmp(line, "sa") == 0)
			a_head = swap(a_head);
		if (ft_strcmp(line, "sb") == 0)
			b_head = swap(b_head);
		if (ft_strcmp(line, "ss") == 0)
		{
			a_head = swap(a_head);
			b_head = swap(b_head);
		}
		compare(line, &a_head, &b_head);
	}
	check_sorted(a_head, b_head);
	return (0);
}
