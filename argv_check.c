/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:00:39 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/15 16:25:48 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_exit(void)
{
	write(2, "Error", 6);
	exit(-1);
}

int	int_check(long num)
{
	if (!(num >= -2147483648 && num <= 2147483647))
		f_exit();
	return (num);
}

int	sort_check(char **av, int len, int num, int num2)
{
	static int	flag;
	int			i_check;
	int			i;

	i = 0;
	if (av[len + 1] && num2 < num)
		flag = 1;
	while (i < len)
	{
		i_check = ft_atoi(av[i]);
		if (i_check == num)
			f_exit();
		i++;
	}
	if (flag != 1 && av[len + 1] == NULL)
		exit(-1);
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