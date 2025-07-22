/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:21 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/22 18:45:29 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tab_copy(t_node *stack, int *size_a)
{
	int	*tab;
	int	i;

	i = 0;
	*size_a = ps_lstsize(stack);
	tab = malloc(sizeof(int) * (*size_a));
	while (stack)
	{
		tab[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (tab);
}

void	tab_tri(int	*tab, int *size_a)
{
	int	key;
	int	i;
	int	j;

	i = 1;
	while (i < *size_a)
	{
		j = i - 1;
		key = tab[i];
		while (j >= 0 && tab[j] > key)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
		i++;
	}
}

void	give_index(t_node *stack, int *tab, int *size_a)
{
	int		i;
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < *size_a)
		{
			if (tab[i] == tmp->value)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	process_chunk(t_stack *stack, int min, int max)
{
	int	i;
	int	pos;

	while (has_chunk(stack->a, min, max))
	{
		pos = get_chunk_pos(stack->a, min, max);
		if (pos > stack->size_a / 2)
		{
			i = stack->size_a - pos;
			while (i--)
				reverse_rot_a(&stack->a);
		}
		else
		{
			while (pos--)
				rotate_a(&stack->a);
		}
		push_b(stack);
	}
}

void	greedy_sort(t_stack *stack)
{
	int	*tab;
	int	chunk_size;
	int	min;
	int	max;
	int	total;

	tab = tab_copy(stack->a, &stack->size_a);
	tab_tri(tab, &stack->size_a);
	give_index(stack->a, tab, &stack->size_a);
	chunk_size = get_chunk_size(stack->size_a);
	min = 0;
	max = chunk_size - 1;
	total = stack->size_a;
	while (min < total)
	{
		process_chunk(stack, min, max);
		min += chunk_size;
		max += chunk_size;
		if (max > total)
			max = total - 1;
	}
	while (stack->b)
		push_b_in_a(stack);
	free(tab);
}
