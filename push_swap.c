/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:54:08 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/06 21:48:54 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	diff_char_check(av + 1);
	if (ac == 2)
		argv_single((av + 1), &stack_a, &stack_b);
	else if (ac > 2)
		argv_double((av + 1), &stack_a, &stack_b);
	//ff_error(stack_a, stack_b);
	return (0);
}
