/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/20 20:56:21 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, stack_b, 0);
	rb(stack_a, stack_b, 0);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, stack_b, 0);
	rrb(stack_a, stack_b, 0);
	write(1, "rrr\n", 4);
}

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{

	printnode(*stack_a);
	rrb(stack_b, stack_a, 1);
	printnode(*stack_a);

}
