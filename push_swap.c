/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:54:08 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/04 05:37:53 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	int		i;
	int		error_i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			error_i = push_arg(&stack_a, ft_atoi(av[i]));
			i++;
		}
		if (error_i == -1)
			error(stack_a, stack_b);
		printnode(stack_a);
	}
	return (0);
}
// Bir fonksiyon -> çalıştırıldığında a ve b stacklarini freeleyip exit yapacak exit (0); 
//(ipucu a ve b stackleri linked listden oluşmuştur linked list nasıl freelenir acaba=?)