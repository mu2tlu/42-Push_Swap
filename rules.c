/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/25 15:37:30 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	d_check(t_stack *x, t_stack *y)
{
	if (!x && !y)
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
		if (d_check(stack, stack->next))
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = s_len(*stack_a);
	if (i == 2)
	{
		if (d_check(*stack_a, (*stack_a)->next))
			sa(stack_a, 1);
	}
	else if (i == 3)
	{
		if (d_ascending(*stack_a) == 0)
			if (d_check(*stack_a, (*stack_a)->next))
			{
				write(1, "a", 1);
			}
	}
	printnode(*stack_a);
	printnode(*stack_b);
}
