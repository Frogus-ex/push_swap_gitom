/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:59:37 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/23 18:55:55 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	check_duplicate(t_node *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack;
	while (tmp->next)
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


static int	validate_args(char **av, t_stack *stack)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (is_numerique(av[i]) != 0)
			return (free_stack(&stack->a), -1);
	}
	return (0);
}

static int	process_values(char **tab, t_stack *stack)
{
	int	i;
	int	value;
	int	error;

	i = -1;
	while (tab[++i])
	{
		value = ft_atol(tab[i], &error);
		if (error)
			return (free_tab(tab), free_stack(&stack->a), -1);
		add_node_back(&stack->a, create_node(value));
		stack->size_a++;
		if (check_duplicate(stack->a) != 0)
			return (free_tab(tab), free_stack(&stack->a), -1);
	}
	return (0);
}

int	parse_input(char **av, t_stack *stack)
{
	char	*joined;
	char	**tab;

	if (validate_args(av, stack) == -1)
		return (-1);
	joined = join_ps(av);
	tab = ft_split(joined, ' ');
	free(joined);
	if (process_values(tab, stack) == -1)
		return (-1);
	free_tab(tab);
	return (0);
}
