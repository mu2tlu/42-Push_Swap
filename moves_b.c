/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:38:05 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/20 20:50:26 by mumutlu          ###   ########.fr       */
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
		f_error(*stack_a);
	else
	{
		first = (*stack_b);
		first2 = (*stack_b)->next;
		while ((*stack_b)->next != NULL)
			(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = first;
		first->next = NULL;
		(*stack_b) = first2;
		if (b == 1)
			write(1, "rb\n", 3);
	}
}

void	rrb(t_stack **stack_a, t_stack **stack_b, int b)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack_b))
		f_error(*stack_a);
	else if ((*stack_b)->next->next != NULL)
	{
		first = (*stack_b);
		while ((*stack_b)->next->next != NULL)
			(*stack_b) = (*stack_b)->next;
		last = (*stack_b)->next;
		(*stack_b)->next = NULL;
		last->next = first;
		(*stack_b) = last;
	}
	else if ((*stack_b)->next != NULL)
	{
		last = (*stack_b)->next;
		(*stack_b)->next = NULL;
		last->next = (*stack_b);
		(*stack_b) = last;
	}
	if (b == 1)
		write(1, "rrb\n", 4);
}
