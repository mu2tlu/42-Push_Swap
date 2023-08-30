/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/30 23:41:20 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	d_ascending(t_stack *stack)
{
	if (s_len(stack) < 2)
		return (1);
	while (stack->next)
	{
		if (!d_check(stack->data, stack->next->data))
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int	s_len(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	pivot(t_stack *stack, int max)
{
	int	i;

	i = s_len(stack);
	while (stack->next && i > (max / 2 + max % 2))
	{
		stack = stack->next;
		i--;
	}
	return (stack->data);
}

int	d_check(int x, int y)
{
	return (x > y);
}

int	sort_int_tab(t_stack *stack, int max)
{
	int		temp;
	t_stack	*iter;
	t_stack	*iter2;

	iter = stack;
	while (iter != NULL) 
	{
		iter2 = iter->next; 
		while (iter2 != NULL) 
		{
			if (d_check(iter->data, iter2->data))
			{
				temp = iter->data;
				iter->data = iter2->data;
				iter2->data = temp;
			}
			iter2 = iter2->next;
		}
		iter = iter->next;
	}
	return (pivot(stack, max));
}
