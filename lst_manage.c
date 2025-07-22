/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:15:26 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/22 18:38:04 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_lstsize(t_node *node)
{
	int	i;

	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	get_min_pos(t_node *stack)
{
	int		i;
	int		min_value;
	int		pos;
	t_node	*tmp;

	i = 0;
	pos = 0;
	tmp = stack;
	min_value = stack->value;
	while (tmp)
	{
		if (min_value > tmp->value)
		{
			min_value = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	get_min_value(t_node *stack)
{
	int		min_value;
	t_node	*tmp;

	tmp = stack;
	if (!stack)
		return (INT_MAX);
	min_value = stack->value;
	while (tmp)
	{
		if (min_value > tmp->value)
			min_value = tmp->value;
		tmp = tmp->next;
	}
	return (min_value);
}

void	get_min_front(t_node **stack)
{
	int		index;
	int		lst_size;
	int		i;

	lst_size = ps_lstsize(*stack);
	index = get_min_pos(*stack);
	i = lst_size - index;
	if (index <= lst_size / 2)
	{
		while (index--)
			rotate_a(stack);
	}
	else
	{
		while (i--)
			reverse_rot_a(stack);
	}
}
