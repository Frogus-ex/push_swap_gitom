/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:59:37 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/22 16:45:18 by tlorette         ###   ########.fr       */
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

int	join_len(char **av)
{
	int	i;
	int	len;
	int	j;

	len = 0;
	i = 1;
	while (av[i])
	{
		j = 0;
		if (i > 1)
			len++;
		while (av[i][j])
		{
			if (av[i][j] == 32 || av[i][j] == '-' || av[i][j] == '+')
				j++;
			else
			{
				len++;
				j++;
			}
		}
		i++;
	}
	return (len + 1);
}

char	*join_ps(char **av)
{
	int		i;
	int		j;
	int		z;
	char	*result;

	i = 1;
	z = 0;
	result = malloc(join_len(av));
	if (!result)
		return (NULL);
	while (av[i])
	{
		if (i > 1)
			result[z++] = 32;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != 32 || av[i][j] != '+')
				result[z++] = av[i][j];
			j++;
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
	while (av[++i])
	{
		if (is_numerique(av[i]) != 0)
			return (free_stack(&stack->a), -1);
	}
	i = -1;
	joined = join_ps(av);
	tab = ft_split(joined, ' ');
	free(joined);
	while (tab[++i])
	{
		value = ft_atol(tab[i]);
		add_node_back(&stack->a, create_node(value));
		stack->size_a++;
		if (check_duplicate(stack->a) != 0)
			return (free_tab(tab), free_stack(&stack->a), -1);
	}
	free_tab(tab);
	return (0);
}
