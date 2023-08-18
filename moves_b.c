/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:38:05 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/18 17:45:47 by mumutlu          ###   ########.fr       */
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
