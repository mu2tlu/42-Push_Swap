/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:38:05 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/25 14:16:56 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}

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

void	rb(t_stack **stack_b, int b)
{
	t_stack	*first;
	t_stack	*first2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
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

void	rrb(t_stack **stack_b, int b)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
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
