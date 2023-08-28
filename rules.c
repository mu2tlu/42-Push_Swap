/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/28 15:34:42 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_2_3(t_stack **stack_a, int i)
{
	if (i == 2 && d_check(*stack_a, (*stack_a)->next))
		sa(stack_a, 1);
	if (i == 3 && !d_check(*stack_a, (*stack_a)->next) 
		&& !d_check(*stack_a, (*stack_a)->next->next))
	{
		rra(stack_a, 1);
		if (d_check(*stack_a, (*stack_a)->next))
			sa(stack_a, 1);
	}
	else if (i == 3 && d_check(*stack_a, (*stack_a)->next)
		&& !d_check(*stack_a, (*stack_a)->next->next))
		sa(stack_a, 1);
	else if (i == 3 && !d_check(*stack_a, (*stack_a)->next) 
		&& d_check(*stack_a, (*stack_a)->next->next))
		rra(stack_a, 1);
	else if (i == 3 && d_check(*stack_a, (*stack_a)->next)
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
	argv_2_3(stack_a, i);

	printnode(*stack_a);
	printnode(*stack_b);
}
