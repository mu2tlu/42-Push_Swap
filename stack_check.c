/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/29 17:32:19 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	d_check(t_stack *x, t_stack *y)
{
	if (!x || !y)
		return (0);
	return (x->data > y->data);
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

int	d_ascending(t_stack *stack)
{
	if (!stack || !stack->next)
		return (0);
	while (stack->next)
	{
		if (!d_check(stack, stack->next))
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
