/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:28:54 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/16 14:07:04 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rotate_a(t_stack *stack)
{
	rotate_stack(&stack->a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack)
{
	rotate_stack(&stack->b);
	printf("rb\n");
}

void	rotate_ab(t_stack *stack)
{
	rotate_stack(&stack->a);
	rotate_stack(&stack->b);
	ft_printf("rr\n");
}
