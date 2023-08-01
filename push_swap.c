/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:54:08 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/01 21:37:03 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;

	stack_a = NULL;
	i = 1;
	if (ac > 1)
	{

		while (av[i])
		{
			push(&stack_a, ft_atoi(av[i]));
			i++;
		}
	}
	printnode(stack_a);
	return (0);
}
