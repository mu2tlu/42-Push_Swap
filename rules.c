/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/25 14:18:48 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	data_check(t_stack *x, t_stack *y)
{
	return (x->data > y->data);
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
	while (*stack_a)
	{
		if ((*stack_a)->next)
		{
			break ;
		}
		else
		{
			if ((*stack_b))
			{
				while ((*stack_b))
				{
					if ((*stack_b)->next)
					{
						pb(stack_a, stack_b);
							if (data_check(*stack_b, (*stack_b)->next))
							{
								rb(stack_b, 1);
								rb(stack_b, 1);
								sb(stack_b, 1);
								if(data_short(stack_b))
									exit(1);
							}
							else
							{
								rrb(stack_b, 1);
								if(data_short(stack_b))
									exit(1);
							}
					}
					else
					{
						pa(stack_a, stack_b);
						if (data_check(*stack_a, (*stack_a)->next))
							sa(stack_a, 1);
						else
							break ;
					}
				}
			}
			else
				break ;
		}
		data_short(stack_a);
	}

	printnode(*stack_b);
	printnode(*stack_a);
}
