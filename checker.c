/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:58:29 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/10 20:01:13 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	free_error(char *rule, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a) && !(*b))
		return ;
	while (*a)
	{
		temp = (*a);
		(*a) = (*a)->next;
		free(temp);
	}
	while (*b)
	{
		temp = (*b);
		(*b) = (*b)->next;
		free(temp);
	}
	free(rule);
	rule = NULL;
	write(2, "Error\n", 6);
	exit(1);
}

void	run_rules(char *rule, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(rule, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(rule, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(rule, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(rule, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(rule, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(rule, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(rule, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(rule, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(rule, "rrr\n"))
		rrr(a, b, 0);
	else if (!ft_strcmp(rule, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(rule, "pb\n"))
		pb(a, b, 0);
	else
		free_error(rule, a, b);
}

void	ft_instructions(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		run_rules(str, a, b);
		free(str);
		str = NULL;
		str = get_next_line(0);
	}
}

void	argv_checker(char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**tab;
	int		error_i;
	int		i;

	i = -1;
	diff_char_check(av);
	tab = new_av(av);
	if (!tab)
		return ;
	while (++i, tab[i])
	{
		error_i = push_arg(stack_a, sort_check(tab, tab[i], stack_a));
		if (error_i == -1)
		{
			free_tab(tab);
			f_error(stack_a);
		}
	}
	free_tab(tab);
	ft_instructions(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
		argv_checker((av + 1), &stack_a, &stack_b);
	if (is_sorted(&stack_a, 'a', ft_stacksize(stack_a)))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	ff_error(&stack_a, &stack_b);
	return (0);
}
