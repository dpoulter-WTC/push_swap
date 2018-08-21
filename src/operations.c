/* ************************************************************************** */
/*                                   _ _ _ ____                               */
/*                                   | | | |___                               */
/*  operations.c                     |_|_| |___                               */
/*                                        ___ _  _ _ _  _ _  _                */
/*  By: coding <marvin@42.fr>              |  |__| | |\ | |_/                 */
/*                                         |  |  | | | \| | \_                */
/*  Created: 2018/08/15 11:54:47 b               ____ ____ ___  ____          */
/*  Updated: 2018/08/15 21:56:46 b               |    |  | |  \ |___          */
/*                                               |___ |__| |__/ |___ .co.za   */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack		*swap(t_stack *head)
{
	int i;

	i = head->val;
	head = insert_after(head, i, head->next);
	head = remove_front(head);
	return (head);
}

t_stack		*push(t_stack *head, t_stack **dst)
{
	int i;

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
	int i;
	t_stack *cursor;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	i = cursor->val;
	head = insert_begin(head, i);
	head = remove_back(head);
	return (head);
}
