/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/28 15:15:41 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_3(t_stack **stack_a)
{
	if (!d_check(*stack_a, (*stack_a)->next) 
		&& !d_check(*stack_a, (*stack_a)->next->next))
	{
		rra(stack_a, 1);
		if (d_check(*stack_a, (*stack_a)->next))
			sa(stack_a, 1);
	}
	else if (d_check(*stack_a, (*stack_a)->next)
		&& !d_check(*stack_a, (*stack_a)->next->next))
		sa(stack_a, 1);
	else if (!d_check(*stack_a, (*stack_a)->next) 
		&& d_check(*stack_a, (*stack_a)->next->next))
		rra(stack_a, 1);
	else if (d_check(*stack_a, (*stack_a)->next)
		&& d_check(*stack_a, (*stack_a)->next->next))
	{
		ra(stack_a, 1);
		if (d_check(*stack_a, (*stack_a)->next))
			sa(stack_a, 1);
	}
}

// void	argv_8(t_stack **stack_a, t_stack **stack_b)
// {
	
// }

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = s_len(*stack_a);
	if (i == 2 && d_check(*stack_a, (*stack_a)->next))
		sa(stack_a, 1);
	else if (i == 3)
		argv_3(stack_a);
	// else if(i > 3)
	// {
	// 	argv_s(stack_a, stack_b);
	// }
	printnode(*stack_a);
	printnode(*stack_b);
}
