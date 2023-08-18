/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:38:05 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/18 17:23:26 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sb(t_stack **stak_b, int b)
{
	t_stack	*temp;

	if (!(*stak_b))
		return ;
	else if ((*stak_b)->next != NULL)
	{
		temp = (*stak_b);
		(*stak_b) = (*stak_b)->next;
		temp->next = (*stak_b)->next;
		(*stak_b)->next = temp;
		if (b == 1)
			write(1, "sb\n", 3);
	}
}
