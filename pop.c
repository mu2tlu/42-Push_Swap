/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:44:21 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/04 05:04:50 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
