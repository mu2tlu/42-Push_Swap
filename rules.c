/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:31:56 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/02 17:56:24 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_2_3(t_stack **stack, int max)
{
	if (max == 2 && d_check((*stack)->data, (*stack)->next->data))
		sa(stack, 1);
	if (max == 3 && !d_check((*stack)->data, (*stack)->next->data) 
		&& !d_check((*stack)->data, (*stack)->next->next->data))
	{
		rra(stack, 1);
		if (d_check((*stack)->data, (*stack)->next->data))
			sa(stack, 1);
	}
	else if (max == 3 && d_check((*stack)->data, (*stack)->next->data)
		&& !d_check((*stack)->data, (*stack)->next->next->data))
		sa(stack, 1);
	else if (max == 3 && !d_check((*stack)->data, (*stack)->next->data) 
		&& d_check((*stack)->data, (*stack)->next->next->data))
		rra(stack, 1);
	else if (max == 3 && d_check((*stack)->data, (*stack)->next->data)
		&& d_check((*stack)->data, (*stack)->next->next->data))
	{
		ra(stack, 1);
		if (d_check((*stack)->data, (*stack)->next->data))
			sa(stack, 1);
	}
}

int	sort_int_tab(t_stack **stack_a, t_stack **stack_b, char flag, int len)
{
	int	temp;
	int	*new_arr;
	int	i;
	int	j;

	i = -1;
	j = -1;
	new_arr = new_stack(stack_a, stack_b, flag, len);
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (new_arr[i] > new_arr[j])
			{
				temp = new_arr[i];
				new_arr[i] = new_arr[j];
				new_arr[j] = temp;
			}
		}
	}
	temp = pivot(new_arr, len);
	free(new_arr);
	return (temp);
}

void	argv_stack(t_stack **stack_a, t_stack **stack_b, int len)
{
	printnode(*stack_a);
	printf("|||%d|||\n", sort_int_tab(stack_a, stack_b, 'a', len));
	printnode(*stack_a);
	(void)stack_b;
}

void	the_rules(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = s_len(*stack_a);
	if (len < 4)
		argv_2_3(stack_a, len);
	else
		argv_stack(stack_a, stack_b, len);
}
