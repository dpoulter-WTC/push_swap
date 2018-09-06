/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  list_functions.c                 |_|_| |___                               */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoulter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:40:27 by dpoulter          #+#    #+#             */
/*  Updated: 2018/09/05 21:02:42 b               |    |  | |  \ |___          */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack		*remove_front(t_stack *head)
{
	t_stack *front;

	if (head == NULL)
		return (NULL);
	front = head;
	head = head->next;
	front->next = NULL;
	if (front == head)
		head = NULL;
	free(front);
	return (head);
}

t_stack		*remove_back(t_stack *head)
{
	t_stack *cursor;
	t_stack *back;

	if (head == NULL)
		return (NULL);
	cursor = head;
	back = NULL;
	while (cursor->next != NULL)
	{
		back = cursor;
		cursor = cursor->next;
	}
	if (back != NULL)
		back->next = NULL;
	if (cursor == head)
		head = NULL;
	free(cursor);
	return (head);
}

t_stack		*create(int data, t_stack *next)
{
	t_stack	*new_stack;

	new_stack = (t_stack*)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		error_code(1);
	new_stack->val = data;
	new_stack->next = next;
	return (new_stack);
}

t_stack		*append(t_stack *head, int data)
{
	t_stack *cursor;
	t_stack *new_node;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	new_node = create(data, NULL);
	cursor->next = new_node;
	return (head);
}

t_stack		*insert_after(t_stack *head, int data, t_stack *prev)
{
	t_stack *cursor;
	t_stack *new_node;

	cursor = head;
	while (cursor != prev)
		cursor = cursor->next;
	new_node = NULL;
	if (cursor != NULL)
	{
		new_node = create(data, cursor->next);
		cursor->next = new_node;
		return (head);
	}
	else
	{
		return (NULL);
	}
}
