/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:18:59 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/03 13:45:36 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_stacksize(t_stack *stack)
{
	size_t	n;

	n = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		n++;
	}
	return (n);
}

void	ft_sort_int_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_middle(int *pivot, t_stack **stack_a, int len)
{
	int		i;
	int		*tmp;
	t_stack	*iter;

	tmp = (int *)malloc(sizeof(int) * len);
	if (!tmp)
		return (0);
	i = 0;
	iter = (*stack_a);
	while (i < len)
	{
		tmp[i] = iter->data;
		iter = iter->next;
		i++;
	}
	ft_sort_int_tmp(tmp, len);
	*pivot = tmp[len / 2];
	free(tmp);
	return (1);
}

int	is_sorted(t_stack **stack, char flag, int len)
{
	int		i;
	t_stack	*first;

	first = (*stack);
	if (flag == 'a')
	{
		i = 1;
		while (i++ < len)
		{
			if (first->data > first->next->data)
				return (0);
			first = first->next;
		}
	}
	else if (flag == 'b')
	{
		i = 1;
		while (i++ < len)
		{
			if (first->data < first->next->data)
				return (0);
			first = first->next;
		}
	}
	return (1);
}

void	sort_three_first(t_stack **stack)
{
	if ((*stack)->data < (*stack)->next->data
		&& (*stack)->data < (*stack)->next->next->data)
	{
		rra(stack, 1);
		if ((*stack)->data > (*stack)->next->data)
			sa(stack, 1);
	}
	else if ((*stack)->data > (*stack)->next->data
		&& (*stack)->data < (*stack)->next->next->data)
		sa(stack, 1);
	else if ((*stack)->data < (*stack)->next->data 
		&& (*stack)->data > (*stack)->next->next->data)
		rra(stack, 1);
	else if ((*stack)->data > (*stack)->next->data
		&& (*stack)->data > (*stack)->next->next->data)
	{
		ra(stack, 1);
		if ((*stack)->data > (*stack)->next->data)
			sa(stack, 1);
	}
}
