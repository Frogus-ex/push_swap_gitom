/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:32:36 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/23 17:36:25 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_pos(t_stack *stack, int target_pos)
{
	int		pos;
	int		i;
	t_node	*tmp;

	i = 0;
	pos = -1;
	tmp = stack->a;
	while (tmp)
	{
		if (tmp->index == target_pos)
		{
			pos = i;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

int	get_target_pos(t_stack *stack, int index_b)
{
	int		pos;
	int		best_pos;
	t_node	*curr;

	pos = 0;
	best_pos = -1;
	curr = stack->a;
	while (curr)
	{
		if (curr->index > index_b && best_pos == -1)
		{
			best_pos = pos;
			break ;
		}
		pos++;
		curr = curr->next;
	}
	if (best_pos == -1)
		return (get_min_pos(stack->a));
	return (best_pos);
}

int	rotate_cost(int size, int target_pos)
{
	int	half;
	int	cost;

	half = size / 2;
	cost = 0;
	if (target_pos == 0)
		return (0);
	if (target_pos <= half)
		cost = target_pos;
	else if (target_pos > half)
		cost = target_pos - size;
	return (cost);
}


