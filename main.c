/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:46:23 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/24 15:56:59 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_sort(t_stack *stack)
{
	if (stack->size_a == 4 || stack->size_a == 5)
		sort_five_four(stack);
	else if (stack->size_a == 3)
		sort_three(stack);
	else if (stack->size_a == 2)
	{
		if (stack->a->value > stack->a->next->value)
			swap_a(&stack->a);
	}
	else if (stack->size_a > 5)
		greedy_sort(stack);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 1)
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	stack.size_a = 0;
	stack.size_b = 0;
	if (parse_input(av, &stack) == -1)
		ft_error(&stack);
	if (stack.size_a <= 1)
	{
		free_stack(&stack.a);
		free_stack(&stack.b);
		return (0);
	}
	if (!is_sorted(stack.a))
		execute_sort(&stack);
	free_stack(&stack.a);
	free_stack(&stack.b);
	return (0);
}


