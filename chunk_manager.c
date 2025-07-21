/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:14:12 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/21 15:33:46 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	int	chunk_size;
	int	chunk_nb;

	chunk_nb = 0;
	if (size <= 100)
		chunk_nb = 5;
	else if (size <= 500)
		chunk_nb = 20;
	else if (size > 500)
		chunk_nb = size / 15 + 3;
	chunk_size = size / chunk_nb;
	return (chunk_size);
}

int	has_chunk(t_node *stack, int min, int max)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	get_chunk_pos(t_node *stack, int min, int max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	get_max_pos(t_node *b)
{
	int		pos;
	int		i;
	int		index_max;
	t_node	*tmp;

	i = 0;
	pos = 0;
	tmp = b;
	index_max = tmp->index;
	while (tmp)
	{
		if (tmp->index > index_max)
		{
			index_max = tmp->index;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

void	push_b_in_a(t_stack *stack)
{
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	pos = get_max_pos(stack->b);
	if (pos <= stack->size_b / 2)
	{
		while (pos--)
			rotate_b(&stack->b);
	}
	else
	{
		i = stack->size_b - pos;
		while (i--)
			reverse_rot_b(&stack->b);
	}
	push_a(stack);
}

