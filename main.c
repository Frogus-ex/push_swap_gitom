/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:46:23 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/17 15:55:39 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 6)
	{
		stack.a = NULL;
		stack.b = NULL;

		add_node_front(&stack.a, create_node(ft_atoi(av[5])));
		add_node_front(&stack.a, create_node(ft_atoi(av[4])));
		add_node_front(&stack.a, create_node(ft_atoi(av[3])));
		add_node_front(&stack.a, create_node(ft_atoi(av[2])));
		add_node_front(&stack.a, create_node(ft_atoi(av[1])));

		sort_five_four(&stack);
		print_stack(stack.a);

		free_stack(&stack.a);
		free_stack(&stack.b);
	}
	return (0);
}


