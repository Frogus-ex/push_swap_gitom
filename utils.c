/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:27:15 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/22 17:08:22 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
	return ;
}

int	is_numerique(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (-1);
	if ((str[i] == '+' && str[i + 1] == '+')
		|| (str[i] == '-' && str[i + 1] == '-'))
		return (-1);
	else if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == 32))
			i++;
		else
			return (-1);
	}
	return (0);
}

void	ft_error(t_stack *stack)
{
	ft_printf("Error\n");
	free_stack(&stack->a);
	free_stack(&stack->b);
	exit (EXIT_FAILURE);
}

int	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result * 10 + (str[i] - '0') > INT_MAX
			|| result * 10 + (str[i] - '0') < INT_MIN)
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
