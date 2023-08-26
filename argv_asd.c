/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_asd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:18:15 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/26 14:32:23 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoll(char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!str)
		return (0);
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

void	free_tab(char **tab)
{
	int	i; 

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	argv_single(char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**tab;
	int		error_i;
	int		check;
	int		i;

	i = 0;
	tab = ft_split(av[0], ' ');
	if (!tab)
		return ;
	if (tab[i + 1] == NULL)
		exit(-1);
	while (tab[i])
	{
		check = sort_check(tab, i, tab[i]);
		error_i = push_arg(stack_a, check);
		if (error_i == -1)
			f_error(*stack_a);
		i++;
	}
	free_tab(tab);
	the_rules(stack_a, stack_b);
}

void	argv_double(char **av, t_stack **stack_a, t_stack **stack_b)
{
	int		error_i;
	int		check;
	int		i;

	i = 0;
	if (av[i + 1] == NULL)
		exit(-1);
	while (av[i])
	{
		check = sort_check(av, i, av[i]);
		error_i = push_arg(stack_a, check);
		if (error_i == -1)
			f_error(*stack_a);
		i++;
	}
	the_rules(stack_a, stack_b);
}
