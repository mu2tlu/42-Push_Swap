/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:44:21 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/05 00:26:14 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	pop(t_stack **node)
{
	t_stack	*temp;
	int		res;

	res = -1;
	if ((*node))
	{
		temp = (*node);
		res = temp->data;
		(*node) = (*node)->next;
		free(temp);
	}
	return (res);
}

int	push(t_stack **node, int num)
{
	t_stack	*temp;

	if (!(*node))
		return (-1);
	else
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			return (-1);
		temp->data = num; 
		temp->next = (*node);
		(*node) = temp;
	}
	return (1);
}
