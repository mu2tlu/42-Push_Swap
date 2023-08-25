/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/25 14:28:06 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	data_check(t_stack *x, t_stack *y)
{
	return (x->data > y->data);
}

int	stack_len(t_stack *stack)
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

int	data_short(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return (0);
	while ((*stack)->next)
	{
		if (data_check(*stack, (*stack)->next))
			(*stack) = (*stack)->next;
		else
			return (0);
	}
	return (1);
}

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{
	if (da(*stack_a), (*stack_a)->next)

	printnode(*stack_b);
	printnode(*stack_a);
}
