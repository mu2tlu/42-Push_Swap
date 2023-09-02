/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:19:32 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/02 19:58:53 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_a(t_stack **a, t_stack **b, int len, int count)
{
	int	pivot;
	int	i;

	if (is_sorted(a, 'a', len))
		return (1);
	i = len;
	if (len <= 3)
	{
		sort_three_a(a, b, len);
		return (1);
	}
	if (!find_middle(&pivot, a, len))
		return (0);
	while (len != i / 2 + i % 2)
	{
		if ((*a)->data < pivot && (len--))
			pb(a, b);
		else if (++count)
			ra(a, 1);
	}
	while ((i / 2 + i % 2) != (int)ft_stacksize(*a) && count--)
		rra(a, 0);
	return (sort_a(a, b, (i / 2 + i % 2), 0)
		&& sort_b(b, a, i / 2, 0));
	return (1);
}

int	sort_b(t_stack **b, t_stack **a, int len, int count)
{
	int	pivot;
	int	i;

	if (!count && is_sorted(b, 'b', len))
		while (len--)
			pa(a, b);
	if (len <= 3)
	{
		sort_small_b(b, a, len);
		return (1);
	}
	i = len;
	if (!find_middle(&pivot, b, len))
		return (0);
	while (len != i / 2)
	{
		if ((*b)->data >= pivot && (len--))
			pa(a, b);
		else if (++count)
			rb(b, 1);
	}
	while (i / 2 != (int)ft_stacksize(*b) && count--)
		rrb(b, 1);
	return (sort_a(a, b, (i / 2 + i % 2), 0)
		&& sort_b(b, a, i / 2, 0));
}

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
