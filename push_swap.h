/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:26:14 by mumutlu           #+#    #+#             */
/*   Updated: 2023/08/06 21:51:00 by mumutlu          ###   ########.fr       */
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
void	diff_char_check(char	**av);
void	space_or_empty_check(char	**av);
void	f_exit(void);
void	ft_split_arr2(char **av, t_stack **stack_a, t_stack	**stack_b);
void	ft_split_arr(char **av, t_stack **stack_a, t_stack	**stack_b);
int		ft_atoll(const char *str);
void	printnode(t_stack *node);//dikakt

#endif
