/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:39:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/23 21:23:45 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	ft_is_increasing(t_stack **stack)
{
	t_node	*tmp;

	if (stack && *stack)
	{
		tmp = (*stack)->head;
		while (tmp)
		{
			if (!tmp->next_node)
				break ;
			if (tmp->data > tmp->next_node->data)
				return (0);
			tmp = tmp->next_node;
		}
	}
	return (1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-(nb));
	return (nb);
}

void	ft_get_max_and_min(t_stack **stack, t_node *num)
{	
	if ((*stack)->size == 0)
	{
		(*stack)->max = num;
		(*stack)->min = num;
		return ;
	}
	else
	{
		if (num->data > (*stack)->max->data)
			(*stack)->max = num;
		else if (num->data < (*stack)->min->data)
			(*stack)->min = num;
	}
}

int	get_index(int *tab, int num, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (tab[i] == num)
			return (i);
	return (-1);
}

void	ft_sorted_indexing(t_stack **stack)
{
	t_node	*tmp;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * (*stack)->size);
	tmp = (*stack)->head;
	i = -1;
	while (tmp)
	{
		tab[++i] = tmp->data;
		tmp = tmp->next_node;
	}
	ft_insertion_sort(tab, (*stack)->size);
	tmp = (*stack)->head;
	while (tmp)
	{
		tmp->sorted_index = get_index(tab, tmp->data, (*stack)->size) + 1;
		tmp = tmp->next_node;
		i++;
	}
	free(tab);
}
