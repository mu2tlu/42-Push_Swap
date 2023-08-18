/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/18 17:37:26 by mumutlu          ###   ########.fr       */
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

void	the_rules(t_stack *stack_a, t_stack *stack_b)
{
    (void) stack_b;
	printnode(stack_a);
}
