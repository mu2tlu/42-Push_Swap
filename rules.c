/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/29 21:42:56 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_2_3(t_stack **stack, int i)
{
	if (i == 2 && d_check((*stack)->data, (*stack)->next->data))
		sa(stack, 1);
	if (i == 3 && !d_check((*stack)->data, (*stack)->next->data) 
		&& !d_check((*stack)->data, (*stack)->next->next->data))
	{
		rra(stack, 1);
		if (d_check((*stack)->data, (*stack)->next->data))
			sa(stack, 1);
	}
	else if (i == 3 && d_check((*stack)->data, (*stack)->next->data)
		&& !d_check((*stack)->data, (*stack)->next->next->data))
		sa(stack, 1);
	else if (i == 3 && !d_check((*stack)->data, (*stack)->next->data) 
		&& d_check((*stack)->data, (*stack)->next->next->data))
		rra(stack, 1);
	else if (i == 3 && d_check((*stack)->data, (*stack)->next->data)
		&& d_check((*stack)->data, (*stack)->next->next->data))
	{
		ra(stack, 1);
		if (d_check((*stack)->data, (*stack)->next->data))
			sa(stack, 1);
	}
}

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = s_len(*stack_a);
	if (i < 4)
		argv_2_3(stack_a, i);
	printnode(*stack_a);
	printnode(*stack_b);
}
