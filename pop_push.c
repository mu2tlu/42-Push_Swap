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

int	pop(t_stack **stack_x, t_stack **stack_y)
{
	t_stack	*temp;
	int		res;

	res = 0;
	if (!*stack_x)
		ff_error(*stack_x, *stack_y);
	else if ((*stack_x)->next)
	{
		temp = (*stack_x);
		res = temp->data;
		(*stack_x) = (*stack_x)->next;
		free(temp);
	}
	else
	{
		res = (*stack_x)->data;
		(*stack_x) = NULL;
		free(*stack_x);
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
