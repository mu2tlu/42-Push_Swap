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

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void	diff_char_check(char	**av);
void	argv(char **av, t_stack **stack_a, t_stack **stack_b);
void	space_or_empty_check(char	**av);
char	**new_av(char **av);
void	free_tab(char **tab);
int		calculate_size(char **av);
int		push_arg(t_stack **node, int num);
int		sort_check(char **av, int len, char *tab);
long	ft_atoll(char *str);
void	ff_error(t_stack	*stack_a, t_stack	*stack_b);
void	f_error(t_stack	*stack);
void	the_rules(t_stack **stack_a, t_stack **stack_b);
void	f_exit(void);
int		pop(t_stack **stack);
int		push(t_stack **stack, int num);
void	sa(t_stack **stack_a, int a);
void	sb(t_stack **stack_b, int b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, int a);
void	rb(t_stack **stack_b, int b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, int a);
void	rrb(t_stack **stack_b, int b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		d_check(int x, int y);
int		d_ascending(t_stack *stack);
int		s_len(t_stack *stack);
void	argv_2_3(t_stack **stack_a, int i);
void	argv_stack(t_stack **stack_a, t_stack **stack_b, int i);

void	printnode(t_stack *node);//dikakt
#endif
