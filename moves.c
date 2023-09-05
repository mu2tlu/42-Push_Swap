/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:52:24 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/05 18:34:58 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ss(t_stack **stack_a, t_stack **stack_b, int ab)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (ab == 1)
		write(1, "ss\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int ab)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (ab == 1)
		write(1, "rr\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int ab)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (ab == 1)
		write(1, "rrr\n", 4);
}
