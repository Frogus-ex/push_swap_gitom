/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:21 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/17 17:40:53 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tab_copy(t_node *stack, int *size_a)
{
	int	*tab;
	int	i;

	i = 0;
	*size_a = ps_lstsize(stack);
	tab = malloc(sizeof(int) * size);
	while (stack)
	{
		tab[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (tab);
}

void	tab_tri(int	*tab, int size)
{
	int	key;
	int	i;
	int	j;

	i = 1;
	while (i < size)
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

void	give_index(t_node *stack, int *tab, int size)
{
	int		i;
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
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
