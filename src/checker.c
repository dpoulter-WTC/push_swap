/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:15:27 by dpoulter          #+#    #+#             */
/*   Updated: 2018/09/06 13:20:03 by dpoulter         ###   ########.fr       */
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
	if (status == 2)
		ft_putstr_fd("Error: Arguments incorrect\n", 2);
	if (status == 3)
		ft_putstr_fd("Error: Dupe number inputted\n", 2);
	if (status == 4)
		ft_putstr_fd("Error: MAX INT\n", 2);
	if (status == 5)
		ft_putstr_fd("Error: Invalid command\n", 2);
	ft_putstr_fd(WHITE, 2);
	if (status == 100)
		return ;
	exit(1);
}

void	populate(char **argv, int argc, t_stack *a_head)
{
	int		i;
	int		j;
	char	**split;
	int		k;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		split = ft_strsplit(argv[i], ' ');
		while (split[++j])
		{
			k = -1;
			while (split[j][++k])
				if (!ft_isdigit(split[j][k]))
					error_code(2);
			if (ft_long_atoi(split[j]) > MAX_INT)
				error_code(4);
			a_head = append(a_head, ft_atoi(split[j]));
			ft_strdel(&split[j]);
		}
		free(split);
	}
	check_dupe(a_head);
}

int		main(int argc, char **argv)
{
	char	*line;
	t_stack	*a_head;
	t_stack	*b_head;

	error_code((argc != 1) ? 100 : 0);
	a_head = create(-3, NULL);
	populate(argv, argc, a_head);
	a_head = remove_front(a_head);
	while (ft_gnl(0, &line))
	{
		recieve(&a_head, &b_head, line);
		free(line);
	}
	check_sorted(a_head, b_head);
	return (0);
}
