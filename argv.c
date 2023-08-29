/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:18:15 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/29 21:27:03 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
			if ((av[y][x] >= '0' && av[y][x] <= '9') && av[y][x + 1] 
				&& (av[y][x + 1] == 32 
				|| (av[y][x + 1] >= 9 && av[y][x + 1] <= 13)))
				k++;
			while (!(av[y][x] >= '0' && av[y][x] <= '9') && av[y][x])
				x++;
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
	k = -1;
	tab1 = (char **) malloc((calculate_size(av)));
	while (++i, av[i])
	{
		tab2 = ft_split(av[i], ' ');
		if (!tab2)
			return (NULL);
		j = -1;
		while (++j, tab2[j])
		{
			tab1[++k] = (char *)malloc((ft_strlen(tab2[j]) + 1) * sizeof(char));
			if (!tab1[k])
				return (NULL);
			ft_strlcpy(tab1[k], tab2[j], ft_strlen(tab2[j]) + 1);
		}
		free_tab(tab2);
	}
	return (tab1);
}

void	argv(char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	**tab;
	int		error_i;
	int		i;

	i = 0;
	diff_char_check(av);
	tab = new_av(av);
	if (!tab)
		return ;
	while (tab[i])
	{
		error_i = push_arg(stack_a, sort_check(tab, i, tab[i]));
		if (error_i == -1)
			f_error(*stack_a);
		i++;
	}
	free_tab(tab);
	the_rules(stack_a, stack_b);
}
