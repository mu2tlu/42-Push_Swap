/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:29:10 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/05 16:40:57 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	if (push(stack_a, pop(stack_b)) == -1)
		ff_error(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	sa(t_stack **stack_a, int a)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	else if ((*stack_a)->next != NULL)
	{
		temp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
		if (a == 1)
			write(1, "sa\n", 3);
	}
}

void	ra(t_stack **stack_a, int a)
{
	t_stack	*first;
	t_stack	*first2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	else
	{
		first = (*stack_a);
		first2 = (*stack_a)->next;
		while ((*stack_a)->next != NULL)
			(*stack_a) = (*stack_a)->next;
		(*stack_a)->next = first;
		first->next = NULL;
		(*stack_a) = first2;
		if (a == 1)
			write(1, "ra\n", 3);
	}
}

void	rra(t_stack **stack_a, int a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	else if ((*stack_a)->next->next != NULL)
	{
		first = (*stack_a);
		while ((*stack_a)->next->next != NULL)
			(*stack_a) = (*stack_a)->next;
		last = (*stack_a)->next;
		(*stack_a)->next = NULL;
		last->next = first;
		(*stack_a) = last;
	}
	else if ((*stack_a)->next != NULL)
	{
		last = (*stack_a)->next;
		(*stack_a)->next = NULL;
		last->next = (*stack_a);
		(*stack_a) = last;
	}
	if (a == 1)
		write(1, "rra\n", 4);
}
