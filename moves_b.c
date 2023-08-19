/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:38:05 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/20 00:00:49 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sb(t_stack **stack_b, int b)
{
	t_stack	*temp;

	if (!(*stack_b))
		return ;
	else if ((*stack_b)->next != NULL)
	{
		temp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
		if (b == 1)
			write(1, "sb\n", 3);
	}
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (!*stack_a)
		return ;
	if (push(stack_b, pop(stack_a, stack_b)) == -1)
		ff_error(*stack_a, *stack_b);
	write(1, "pa\n", 3);
}

void	rb(t_stack **stack_a, t_stack **stack_b, int b)
{
	t_stack	*first;
	t_stack	*first2;

	if (!(*stack_b))
		ff_error(*stack_a, NULL);
	else
	{
		first2 = (*stack_b)->next;
		first = (*stack_b);
		while ((*stack_b)->next != NULL)
			(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = first;
		first->next = NULL;
		(*stack_b) = first2;
		if (b == 1)
			write(1, "rb\n", 3);
	}
}
