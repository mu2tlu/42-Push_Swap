/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:26:14 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/04 05:22:41 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

int		push_arg(t_stack **node, int num);
int		push(t_stack **node, int num);
int		pop(t_stack **node);
void	error(t_stack	*stack_a, t_stack	*stack_b);
void	printnode(t_stack *node);//dikakt

#endif
