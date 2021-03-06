/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:36:54 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/25 01:08:09 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdbool.h>
# include<limits.h>
# include "types.h"

// Manage errors functions
void	ft_error(const char *err_msg, t_stack **stack);
void	ft_free_all(t_stack **stack);
// Helper function
void	ft_init_stack(t_stack **stack);
int		ft_is_increasing(t_stack **stack);
int		ft_abs(int nb);
void	ft_get_max_and_min(t_stack **stack, t_node *num);
void	ft_swap(int *n1, int *n2);
void	ft_insertion_sort(int *tab, int size);
int		get_index(int *tab, int num, int size);
void	ft_sorted_indexing(t_stack **stack);
void	ft_index_stack(t_stack **stack);
void	ft_print_stack(t_stack **stack);
// Parssing arguments functions
int		is_in_int_range(long n);
char	*is_str_digit(char *s);
void	ft_parssing_args(int ac, char **av, t_stack **stack);
// Manage stacks functions
t_node	*ft_new_node(int data);
void	ft_add_node_at_first(t_stack **stack, t_node *new_node);
// Stack sorting instructions
void	swap_stack(t_stack **stack, char s);
void	sswap_stack(t_stack **stack_a, t_stack **stack_b, char c);
void	push_stack(t_stack **src_stack, t_stack **dst_stack, char s);
void	rotate_stack(t_stack **stack, char s);
void	rrotate_stack(t_stack **stack_1, t_stack **stack_2, char c);
void	reverse_rotate_stack(t_stack **stack, char s);
void	rreverse_rotate_stack(t_stack **stack_1, t_stack **stack_2, char c);
// Stack sorting algorithm
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b);
void	ft_lis(t_stack **stack);
void	get_lis_from_stack(t_stack **stack);
void	ft_push_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void	ft_best_move(t_stack **stack_a, t_stack **stack_b);
void	put_lowest_to_top(t_stack **stack_a);
void	execte_moves(t_node *node, t_stack **stack_a, t_stack **stack_b);

#endif