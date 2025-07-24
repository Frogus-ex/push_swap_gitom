/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:59:37 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/24 15:59:39 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_node *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (-1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	add_value_to_stack(char *str, t_stack *stack)
{
	int		value;
	int		error;
	t_node	*new_node;

	if (!str || !*str)
		return (-1);
	value = ft_atol(str, &error);
	if (error)
		return (-1);
	new_node = create_node(value);
	if (!new_node)
		return (-1);
	add_node_back(&stack->a, new_node);
	stack->size_a++;
	if (check_duplicate(stack->a) != 0)
		return (-1);
	return (0);
}

static int	process_values(char **tab, t_stack *stack)
{
	int	i;

	if (!tab || !tab[0])
		return (free_tab(tab), -1);
	i = -1;
	while (tab[++i])
	{
		if (add_value_to_stack(tab[i], stack) == -1)
			return (free_tab(tab), free_stack(&stack->a), -1);
	}
	return (0);
}

int	parse_input(char **av, t_stack *stack)
{
	char	*joined;
	char	**tab;

	joined = join_ps(av);
	tab = ft_split(joined, ' ');
	free(joined);
	if (process_values(tab, stack) == -1)
		return (-1);
	free_tab(tab);
	return (0);
}
