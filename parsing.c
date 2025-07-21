/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:59:37 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/21 19:30:58 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*join_ps(char **av)
{
	int		i;
	int		j;
	int		z;
	char	*result;

	i = 1;
	z = 0;
	result = malloc(sizeof(char) * 100000);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 32)
				j++;
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (av[i][j] == '-')
				{
					result[z] = '-';
					z++;
				}
				j++;
			}
			while (ft_isdigit(av[i][j]))
			{
				result[z] = av[i][j];
				z++;
				j++;
			}
			result[z] = 32;
			z++;
		}
		i++;
	}
	result[z] = '\0';
	return (result);
}

int	parse_input(char **av, t_stack *stack)
{
	int		i;
	int		value;
	char	*joined;
	char	**tab;

	i = 0;
	joined = join_ps(av);
	tab = ft_split(joined, ' ');
	free(joined);
	while (tab[i])
	{
		if (is_numerique(tab[i]) != 0)
			return (free_stack(&stack->a), -1);
		value = ft_atol(stack, tab[i]);
		add_node_back(&stack->a, create_node(value));
		if (check_duplicate(stack->a) != 0)
			return (free_stack(&stack->a), -1);
		i++;
	}
	free(tab);
	return (0);
}
