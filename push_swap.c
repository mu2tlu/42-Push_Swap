/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:54:08 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/06 21:48:54 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

char	*argument_check(char	*str)
{
	int	i;

	i = 0;
	while ((str[i] == 32 || (str[i] <= 9 || str[i] <= 13)) && str[i])
		i++;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-') 
		{

			if (str[i + 1] == '\0' || (str[i + 1] <= 47 || str[i + 1] >= 58))
			{
				write(2, "Error", 6);
				exit(-1);
			}
		}
		else if ((!(str[i] >= '0' && str[i] <= '9')))
		{
			write(2, "Error", 6);
			exit(-1);
		}
		i++;
	}
	return (str);
}

char	**new_arr(char	**av)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	j = 0;
	tab = NULL;
	if (!av)
		return (NULL);
	while (av[i])
		i++;
	tab = (char **)malloc((i + 1) * sizeof(char *));
	i = 1;
	while (av[i])
	{
		tab[j] = argument_check(av[i]);
		i++;
		j++;
	}
	tab[j] = 0;
	//system("leaks push_swap");
	return (tab);
}

int	main(int ac, char **av)
{
	int		i;
	int		error_i;
	char	**tab;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (ac > 1)
	{
		tab = new_arr(av);
		while (tab[i])
		{
			error_i = push_arg(&stack_a, ft_atoi(tab[i]));
			i++;
		}
		if (error_i == -1)
			error(stack_a, stack_b);
		printnode(stack_a);
	}
	return (0);
}
