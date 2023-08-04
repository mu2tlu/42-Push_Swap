/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:54:29 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/04 00:44:00 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	printnode(t_stack *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}
