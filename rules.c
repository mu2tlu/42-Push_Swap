/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/28 16:16:29 by mumutlu          ###   ########.fr       */
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

void	argv_stack(t_stack **stack_a, t_stack **stack_b, int i)
{
	while (stack_a)
	{
		if (d_ascending(stack_a) && i == s_len(stack_a))
			break ;
	}
}

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = s_len(*stack_a);
	if (i < 4)
		argv_2_3(stack_a, i);
	else
		argv_stack(stack_a, stack_b, i);
	printnode(*stack_a);
	printnode(*stack_b);
}
