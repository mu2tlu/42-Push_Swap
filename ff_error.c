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

void	max_min_int(char **av)
{
	long		num;
	int			i;

	i = 0;
	while (av[i])
	{
		num = ft_atoll(av[i]);
		if (!(num >= -2147483648 && num <= 2147483647))
		{
			free_tab(av);
			f_exit();
		}
		i++;
	}
}