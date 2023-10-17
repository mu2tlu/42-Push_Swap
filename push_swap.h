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
int		the_numbers_ordered(char **av);
void	max_min_int(char **av);
int		push_arg(t_stack **node, int num);
int		sort_check(char **av, char *tab, t_stack **stack_a);
long	ft_atoll(char *str);
void	ff_error(t_stack	**stack_a, t_stack	**stack_b);
void	f_error(t_stack	**stack);
void	f_exit(void);
int		pop(t_stack **stack);
int		push(t_stack **stack, int num);
void	ss(t_stack **stack_a, t_stack **stack_b, int ab);
void	sa(t_stack **stack_a, int a);
void	sb(t_stack **stack_b, int b);
void	rr(t_stack **stack_a, t_stack **stack_b, int ab);
void	ra(t_stack **stack_a, int a);
void	rb(t_stack **stack_b, int b);
void	rrr(t_stack **stack_a, t_stack **stack_b, int ab);
void	rra(t_stack **stack_a, int a);
void	rrb(t_stack **stack_b, int b);
void	pa(t_stack **stack_a, t_stack **stack_b, int a);
void	pb(t_stack **stack_a, t_stack **stack_b, int b);
void	ft_sort_int_tmp(int *tmp_stack, int size);
int		find_middle(int *pivot, t_stack **stack_a, int len);
int		is_sorted(t_stack **stack, char flag, int len);
void	sort_three_first(t_stack **stack);
void	sort_three_a_i(t_stack **a, t_stack **b, int len);
void	sort_three_a(t_stack **a, t_stack **b, int len);
void	sort_small_b_i(t_stack **b, t_stack **a, int len);
void	sort_small_b(t_stack **b, t_stack **a, int len);
void	ft_sort(t_stack **a, t_stack **b, int len);
int		sort_a(t_stack **a, t_stack **b, int len, int count);
int		sort_b(t_stack **b, t_stack **a, int len, int count);
size_t	ft_stacksize(t_stack *stack);

void	free_error(char *rule, t_stack **a, t_stack **b);
void	run_rules(char *rule, t_stack **a, t_stack **b);
void	ft_instructions(t_stack **a, t_stack **b);
void	argv_checker(char **av, t_stack **stack_a, t_stack **stack_b);

char	*get_next_line(int fd);
void	*ft_free_stash(char **stash, int create_line);
char	*ft_extract_line(char *stash);
int		ft_have_nl(char *s);
char	*ft_copy_to_stash(char *stash, char *buf);
char	*ft_recreate_stash(char *stash);

#endif
