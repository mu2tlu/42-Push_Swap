/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:18:15 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/09 14:33:23 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

int	calculate_size(char **av)
{
	int	x;
	int	y;
	int	k;

	y = 0;
	k = 0;
	while (av[y])
	{
		x = 0;
		while (av[y][x])
		{
			if ((av[y][x] >= '0' && av[y][x] <= '9') 
			&& av[y][x + 1] && (av[y][x + 1] == ' ' 
			|| (av[y][x + 1] >= 9 && av[y][x + 1] <= 13)))
			{
				k++;
			}
			x++;
		}
		y++;
	}
	return ((y + k + 2) * sizeof(char *));
}

char	**new_av(char **av)
{
	char	**tab1;
	char	**tab2;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	tab1 = (char **) malloc((calculate_size(av)));
	if (!tab1)
		return (NULL);
	while (++i, av[i])
	{
		tab2 = ft_split(av[i], ' ');
		if (!tab2)
			return (NULL);
		j = -1;
		while (++j, tab2[j])
		{
			tab1[k] = (char *)malloc((ft_strlen(tab2[j]) + 1) * sizeof(char));
			ft_strlcpy(tab1[k++], tab2[j], ft_strlen(tab2[j]) + 1);
		}
		free_tab(tab2);
	}
	return (tab1[k] = 0, tab1);
}

void	argv(char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**tab;
	int		error_i;
	int		i;

	i = -1;
	diff_char_check(av);
	tab = new_av(av);
	if (!tab)
		return ;
	if (the_numbers_ordered(tab) == 0)
	{
		free_tab(tab);
		exit(-1);
	}
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
	ft_sort(stack_a, stack_b, ft_stacksize(*stack_a));
}
