/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:52:53 by dpoulter          #+#    #+#             */
/*   Updated: 2018/09/05 11:53:29 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack		*insert_begin(t_stack *head, int data)
{
	t_stack *new_node;

	new_node = create(data, head);
	head = new_node;
	return (head);
}

int			stack_size(t_stack *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
