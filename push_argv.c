/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:48:09 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/04 00:41:45 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	push_arg(t_stack **node, int num)
{
	t_stack	*iter;
	t_stack	*temp;

	iter = (*node);
	if ((*node) == NULL)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			return (-1);
		temp->data = num;
		temp->next = NULL;
		(*node) = temp; 
	}
	else
	{
		while (iter->next != NULL)
			iter = iter->next;
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			return (-1);
		temp->data = num;
		iter->next = temp;
		temp->next = NULL;
	}
	return (1);
}
