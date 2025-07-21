/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:46:23 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/21 19:20:46 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	stack.size_a = 0;
	stack.size_b = 0;
	i = 1;
	if (parse_input(av, &stack) == -1)
		ft_error(&stack, "parsing");
	else if (ac == 6 || ac == 5)
		sort_five_four(&stack);
	else if (ac == 4)
		sort_three(&stack);
	else if (ac == 3)
	{
		if (stack.a->value > stack.a->next->value)
			swap_a(&stack.a);
	}
	else if (ac > 6)
		greedy_sort(&stack);
	// print_stack(stack.a);
	free_stack(&stack.a);
	free_stack(&stack.b);
	return (0);
}


