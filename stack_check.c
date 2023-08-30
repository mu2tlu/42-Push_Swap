/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/31 02:21:57 by mumutlu          ###   ########.fr       */
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

int	d_check(int x, int y)
{
	return (x > y);
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

int	pivot(int *new_arr, int max)
{
	int	size;
	int	i;

	i = 0;
	size = max;
	while (new_arr[i] && size > (max / 2 + max % 2))
	{
		i++;
		size--;
	}
	return (new_arr[i]);
}

int	*new_stack(t_stack *stack, int max)
{
	int	i;
	int	*new_arr;

	i = 0;
	new_arr = (int *)malloc(sizeof(int) * max);
	while (stack)
	{
		new_arr[i] = stack->data;
		i++;
		stack = stack->next;
	}
	return (new_arr);
}
