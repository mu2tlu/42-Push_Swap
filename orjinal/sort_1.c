/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:18:59 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/02 19:52:42 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_min(t_stack **stack)
{
	t_stack	*iter;
	int		min;

	iter = *stack;
	min = iter->data;
	while (iter->next)
	{
		if (iter->next->data < min)
			min = iter->next->data;
		iter = iter->next;
	}
	return (min);
}

void	sort_three_first(t_stack **stack, char flag)
{
	if (!is_sorted(stack, flag, 3))
	{
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data < (*stack)->next->data)
			ra(stack, 1);
		if (find_min(stack) == (*stack)->next->data
			&& (*stack)->data > (*stack)->next->data)
			sa(stack, 1);
		if (find_min(stack) == (*stack)->data
			&& (*stack)->next->data > (*stack)->next->next->data)
			rra(stack, 1);
		if (find_min(stack) == (*stack)->data
			&& (*stack)->next->data < (*stack)->data)
		{
			ra(stack, 1);
			sa(stack, 1);
		}
		if (find_min(stack) == (*stack)->data
			&& (*stack)->data < (*stack)->next->data)
		{
			rra(stack, 1);
			sa(stack, 1);
		}
	}
}
