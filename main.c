/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:46:23 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/16 14:06:01 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;

	add_node_front(&stack.a, create_node(4));
	add_node_front(&stack.a, create_node(3));
	add_node_front(&stack.a, create_node(2));
	add_node_front(&stack.a, create_node(1));

	add_node_front(&stack.b, create_node(14));
	add_node_front(&stack.b, create_node(13));
	add_node_front(&stack.b, create_node(12));
	add_node_front(&stack.b, create_node(11));
	// ft_printf("Avant ss:\n");
	// print_stack(stack.a);
	// print_stack(stack.b);

	// swap_ss(&stack);

	// ft_printf("Après ss:\n");
	// print_stack(stack.a);
	// print_stack(stack.b);

	// push_b(&stack);
	// push_b(&stack);
	// push_a(&stack);
	// ft_printf("pile A\n");
	print_stack(stack.a);
	// ft_printf("pile B\n");
	print_stack(stack.b);

	rotate_a(&stack);
	rotate_b(&stack);
	ft_printf("pile A\n");
	print_stack(stack.a);
	ft_printf("pile B\n");
	print_stack(stack.b);
	rotate_ab(&stack);
	ft_printf("pile A\n");
	print_stack(stack.a);
	ft_printf("pile B\n");
	print_stack(stack.b);

	free_stack(&stack.a);
	free_stack(&stack.b);

	return (0);
}


