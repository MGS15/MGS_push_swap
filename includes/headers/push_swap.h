/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:36:54 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/06 22:56:14 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<limits.h>
# include "types.h"

void	ft_error(const char *err_msg);
void	ft_handle_args(int ac, char *av);
int	    is_in_int_range(long n);
char	*is_str_digit(char *s);
void	ft_parssing_args(int ac, char **av);
t_node	*ft_new_node(int data);
void	ft_add_node_at_first(t_stack **stack, t_node *new_node);
void	ft_push_to_stack(t_stack **stack, char **v, int c);
void	ft_valiate_input(char *s);

#endif