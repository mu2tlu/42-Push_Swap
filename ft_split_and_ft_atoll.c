/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_and_ft_atoll.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:18:15 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/08 16:45:49 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoll(const char *str)
{
	long				i;
	long				sign;
	unsigned long int	result;

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

void	ft_split_arr(char **av, t_stack **stack_a, t_stack	**stack_b)
{
	char	**tab;
	int		error_i;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		tab = ft_split(av[i], ' ');
		j = 0;
		while (tab[j])
		{
			error_i = push_arg(stack_a, ft_atoll(tab[j]));
			if (error_i == -1)
				error(*stack_a, *stack_b);
			j++;
		}
		i++;
	}
}


