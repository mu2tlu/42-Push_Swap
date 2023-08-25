/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/25 15:02:17 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	data_check(t_stack *x, t_stack *y)
{
	if (!x && !y)
		return (0);
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

int	data_short(t_stack *stack)
{
	if (!stack->next)
		return (0);
	while (stack->next)
	{
		if (data_check(stack, stack->next))
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = stack_len(*stack_a);
	if (i == 2)
		if (data_check(*stack_a, (*stack_a)->next))
			sa(stack_a, 1);
	data_short(*stack_a);
	printnode(*stack_b);
	printnode(*stack_a);
}
