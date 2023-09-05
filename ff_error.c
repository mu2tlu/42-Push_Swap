/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:39:04 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/16 19:11:07 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ff_error(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*temp;

	while (*stack_a)
	{
		temp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		free(temp);
	}
	while (*stack_b)
	{
		temp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		free(temp);
	}
	exit(1);
}

void	f_error(t_stack	**stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		free(temp);
	}
	exit(1);
}
