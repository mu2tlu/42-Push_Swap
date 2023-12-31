/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:44:21 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/05 00:26:14 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	push_arg(t_stack **node, int num)
{
	t_stack	*iter;
	t_stack	*temp;

	iter = (*node);
	if ((*node) == NULL)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			return (-1);
		temp->data = num;
		temp->next = NULL;
		(*node) = temp; 
	}
	else
	{
		while (iter->next != NULL)
			iter = iter->next;
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			return (-1);
		temp->data = num;
		iter->next = temp;
		temp->next = NULL;
	}
	return (1);
}

int	pop(t_stack **stack)
{
	t_stack	*temp;
	int		res;

	res = 0;
	if ((*stack)->next)
	{
		temp = (*stack);
		res = temp->data;
		(*stack) = (*stack)->next;
		free(temp);
	}
	else
	{
		res = (*stack)->data;
		free(*stack);
		(*stack) = NULL;
	}
	return (res);
}

int	push(t_stack **stack, int num)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = (t_stack *)malloc(sizeof(t_stack));
		if (!*stack)
			return (-1);
		(*stack)->data = num;
		(*stack)->next = NULL;
	}
	else
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			return (-1);
		temp->data = num; 
		temp->next = (*stack);
		(*stack) = temp;
	}
	return (1);
}
