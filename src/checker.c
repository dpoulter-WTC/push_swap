/* ************************************************************************** */
/*                                   _ _ _ ____                               */
/*                                   | | | |___                               */
/*  checker.c                        |_|_| |___                               */
/*                                        ___ _  _ _ _  _ _  _                */
/*  By: coding <marvin@42.fr>              |  |__| | |\ | |_/                 */
/*                                         |  |  | | | \| | \_                */
/*  Created: 2018/08/03 21:55:41 b               ____ ____ ___  ____          */
/*  Updated: 2018/08/21 11:20:14 b               |    |  | |  \ |___          */
/*                                               |___ |__| |__/ |___ .co.za   */
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
	int i;
	int j;
	char **split;

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

int		main(int argc, char **argv)
{
	char	*line;
	int		f;
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack *test_a;
	t_stack *test_b;

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
		if (ft_strcmp(line, "pa") == 0)
			b_head = push(b_head, &a_head);
		if (ft_strcmp(line, "pb") == 0)
			a_head = push(a_head, &b_head);
		if (ft_strcmp(line, "ra") == 0)
			a_head = rotate(a_head);
		if (ft_strcmp(line, "rb") == 0)
			b_head = rotate(b_head);
		if (ft_strcmp(line, "rr") == 0)
		{
			a_head = rotate(a_head);
			b_head = rotate(b_head);
		}
		if (ft_strcmp(line, "rra") == 0)
			a_head = rrotate(a_head);
		if (ft_strcmp(line, "rrb") == 0)
			b_head = rrotate(b_head);
		if (ft_strcmp(line, "rrr") == 0)
		{
			a_head = rrotate(a_head);
			b_head = rrotate(b_head);
		}
		test_a = a_head;
		test_b = b_head;
		while (test_a)
		{
			fprintf(stdout, "%d ", test_a->val);
			fflush(stdout);
			test_a = test_a->next;
		}
			fprintf(stdout, "\n");
			fflush(stdout);
		while (test_b)
		{
			fprintf(stdout, "%d ", test_b->val);
			fflush(stdout);
			test_b = test_b->next;
		}
			fprintf(stdout, "\n");
			fflush(stdout);
	}
	check_sorted(a_head, b_head);
	return (0);
}