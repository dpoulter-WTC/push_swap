/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:54:26 by dpoulter          #+#    #+#             */
/*   Updated: 2018/09/06 11:42:58 by dpoulter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack		*swap(t_stack *head)
{
	int i;

	i = head->val;
	head->val = head->next->val;
	head->next->val = i;
	return (head);
}

t_stack		*push(t_stack *head, t_stack **dst)
{
	int i;

	i = 0;
	if (!head)
		return (head);
	i = head->val;
	if (!*dst)
		*dst = create(i, NULL);
	else
		dst[0] = insert_begin(dst[0], i);
	head = remove_front(head);
	return (head);
}

t_stack		*rotate(t_stack *head)
{
	int i;

	i = head->val;
	head = append(head, i);
	head = remove_front(head);
	return (head);
}

t_stack		*rrotate(t_stack *head)
{
	int		i;
	t_stack	*cursor;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	i = cursor->val;
	head = insert_begin(head, i);
	head = remove_back(head);
	return (head);
}
