/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_and_ft_atoll.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:18:15 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/10 19:42:04 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoll(const char	*str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_split_arr2(char **av, t_stack **stack_a, t_stack	**stack_b)
{
	char	**tab;
	int		error_i;
	int		check;
	int		size;
	int		i;

	i = 0;
	size = 0;
	tab = ft_split(av[1], ' ');
	if (!tab)
		return ;
	while (tab[size])
		size++;
	if (size == 1)
		exit(-1);
	while (tab[i])
	{
		check = sort_check(tab, integer_check(ft_atoll(tab[i])));
		error_i = push_arg(stack_a, check);
		if (error_i == -1)
			error(*stack_a, *stack_b);
		i++;
	}
}

void	ft_split_arr(char **av, t_stack **stack_a, t_stack	**stack_b)
{
	int		error_i;
	int		check;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (av[size])
		size++;
	if (size == 1)
		exit(-1);
	while (av[i])
	{
		check = sort_check(av, integer_check(ft_atoll(av[i])));
		error_i = push_arg(stack_a, check);
		if (error_i == -1)
			error(*stack_a, *stack_b);
		i++;
	}
}
