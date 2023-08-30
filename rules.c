/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/30 23:42:08 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_2_3(t_stack **stack, int max)
{
	if (max == 2 && d_check((*stack)->data, (*stack)->next->data))
		sa(stack, 1);
	if (max == 3 && !d_check((*stack)->data, (*stack)->next->data) 
		&& !d_check((*stack)->data, (*stack)->next->next->data))
	{
		rra(stack, 1);
		if (d_check((*stack)->data, (*stack)->next->data))
			sa(stack, 1);
	}
	else if (max == 3 && d_check((*stack)->data, (*stack)->next->data)
		&& !d_check((*stack)->data, (*stack)->next->next->data))
		sa(stack, 1);
	else if (max == 3 && !d_check((*stack)->data, (*stack)->next->data) 
		&& d_check((*stack)->data, (*stack)->next->next->data))
		rra(stack, 1);
	else if (max == 3 && d_check((*stack)->data, (*stack)->next->data)
		&& d_check((*stack)->data, (*stack)->next->next->data))
	{
		ra(stack, 1);
		if (d_check((*stack)->data, (*stack)->next->data))
			sa(stack, 1);
	}
}


void	argv_stack(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	pivot;

	pivot = sort_int_tab(*stack_a, max);
	while (stack_a)

	{
		if (d_check((*stack_a)->data, pivot))
			ra(stack_a, 1);
		else
		{
			sa(stack_a, 1);
			pb(stack_a, stack_b);
		}
	}
}

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{
	int	max;

	max = s_len(*stack_a);
	if (max < 4)
		argv_2_3(stack_a, max);
	else
		argv_stack(stack_a, stack_b, max);
}

