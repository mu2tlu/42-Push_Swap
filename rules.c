/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/18 20:05:49 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(&stack_a, 0);
	sb(&stack_b, 0);
	write(1, "ss\n", 3);
}

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{
	push (stack_b, 5);
	push (stack_b, 4);
	push (stack_b, 3);
	push (stack_b, 2);
	push (stack_b, 1);
	write(1, "a\n", 2);
	printnode(*stack_a);
	write(1, "b\n", 2);
	printnode(*stack_b);
	pa(stack_a, stack_b);
	sa(stack_a, 1);
	sb(stack_b, 1);
	write(1, "a\n", 2);
	printnode(*stack_a);
	write(1, "b\n", 2);
	printnode(*stack_b);
}
