/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:00:39 by mumutlu           #+#    #+#             */
/*   Updated: 2023/09/05 23:26:15 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	f_exit(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int	the_numbers_ordered(char **av)
{
	static int	flag;
	long		num;
	int			i;

	i = 0;
	while (av[i])
	{
		num = ft_atoll(av[i]);
		if (!(num >= -2147483648 && num <= 2147483647))
		{
			free_tab(av);
			f_exit();
		}
		if (flag == 0)
		{
			if (i >= 1 && num <= ft_atoi(av[i - 1]))
				flag = 1;
		}
		i++;
	}
	return (flag);
}

int	sort_check(char **av, char *tab, t_stack **stack_a)
{
	int		i_check;
	long	num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_atoi(tab);
	while (av[i])
	{
		i_check = ft_atoi(av[i]);
		if (i_check == num)
		{
			j += 1;
			if (j >= 2)
			{
				free_tab(av);
				write(2, "Error\n", 6);
				f_error(stack_a);
			}
		}
		i++;
	}
	return (num);
}

void	space_or_empty_check(char	**av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (!(av[i][j]))
			f_exit();
		while (av[i][j] && (av[i][j] == 32 
		|| (av[i][j] >= 9 && av[i][j] <= 13)))
		{
			if (av[i][j + 1] == '\0')
				f_exit();
			j++;
		}
		i++;
	}
}

void	diff_char_check(char	**av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	space_or_empty_check(av);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j + 1] == '\0' 
					|| (!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9')))
					f_exit();
			}
			else if (!(av[i][j] >= '0' && av[i][j] <= '9') 
				&& !(av[i][j] == 32 || (av[i][j] >= 9 && av[i][j] <= 13)))
				f_exit();
			j++;
		}
		i++;
	}
}
