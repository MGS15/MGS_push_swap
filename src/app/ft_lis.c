/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:57:11 by sel-kham          #+#    #+#             */
/*   Updated: 2022/04/21 22:27:36 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	ft_get_max_num(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

static void	fill_stack(t_stack **stack)
{
	int		i;
	t_node	*tmp;

	tmp = (*stack)->head;
	i = 0;
	while (tmp)
	{
		tmp->index = i++;
		tmp->lis = 1;
		tmp->is_in_lis = false;
		tmp = tmp->next_node;
	}
}

void	ft_lis(t_stack **stack)
{
	int		i;
	int		j;
	t_node	*current;
	t_node	*previous;

	fill_stack(stack);
	current = (*stack)->min->previous_node;
	i = (*stack)->size;
	while (i--)
	{
		previous = current;
		j = i;
		while (++j < (*stack)->size)
		{
			previous = previous->next_node;
			if (!previous)
				previous = (*stack)->head;
			if (current->data < previous->data)
				current->lis = ft_get_max_num(current->lis, previous->lis + 1);
		}
		current = current->previous_node;
	}
}

void	get_lis_from_stack(t_stack **stack)
{
	t_node	*tmp;
	int		searcher;
	int		i;

	ft_lis(stack);
	tmp = (*stack)->min;
	tmp->is_in_lis = true;
	searcher = tmp->lis;
	i = -1;
	while (++i < (*stack)->size)
	{
		if (tmp->lis == searcher - 1)
		{
			tmp->is_in_lis = true;
			searcher--;
		}
		tmp = tmp->next_node;
		if (!tmp)
			tmp = (*stack)->head;
	}
}
