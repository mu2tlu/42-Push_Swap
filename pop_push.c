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

int	pop(t_stack **node_x, t_stack **node_y)
{
	t_stack	*temp;
	int		res;

	res = 0;
	if (!*node_x)
		ff_error(*node_x, *node_y);
	else if ((*node_x)->next)
	{
		temp = (*node_x);
		res = temp->data;
		(*node_x) = (*node_x)->next;
		free(temp);
	}
	else
	{
		res = (*node_x)->data;
		(*node_x) = NULL;
		free(*node_x);
	}
	return (res);
}

int	push(t_stack **node, int num)
{
	t_stack	*temp;

	if (!*node)
	{
		*node = (t_stack *)malloc(sizeof(t_stack));
		if (!*node)
			return (-1);
		(*node)->data = num;
		(*node)->next = NULL;
	}
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
