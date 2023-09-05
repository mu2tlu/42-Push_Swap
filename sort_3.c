/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:19:32 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/05 18:38:38 by mumutlu          ###   ########.fr       */
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
			pb(a, b, 1);
		else if (++count)
			ra(a, 1);
	}
	while ((i / 2 + i % 2) != (int)ft_stacksize(*a) && count--)
		rra(a, 0);
	return (sort_a(a, b, (i / 2 + i % 2), 0)
		&& sort_b(b, a, i / 2, 0));
}

int	sort_b(t_stack **b, t_stack **a, int len, int count)
{
	int	pivot;
	int	i;

	if (!count && is_sorted(b, 'b', len))
		while (len--)
			pa(a, b, 1);
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
			pa(a, b, 1);
		else if (++count)
			rb(b, 1);
	}
	while (i / 2 != (int)ft_stacksize(*b) && count--)
		rrb(b, 1);
	return (sort_a(a, b, (i / 2 + i % 2), 0)
		&& sort_b(b, a, i / 2, 0));
}

void	ft_sort(t_stack **a, t_stack **b, int len)
{
	if (!is_sorted(a, 'a', len))
	{
		if (len == 2)
			sa(a, 1);
		else if (len == 3)
			sort_three_first(a);
		else
			sort_a(a, b, len, 0);
	}
}
