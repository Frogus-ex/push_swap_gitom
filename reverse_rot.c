/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:08:06 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/16 16:11:37 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rot_stack(t_node **stack)
{
	t_node	*before_last;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_rot_a(t_stack *stack)
{
	reverse_rot_stack(&stack.a);
	ft_printf("rra\n");
}

void	reverse_rot_b(t_stack *stack)
{
	reverse_rot_stack(&stack.b);
	ft_printf("rrb\n");
}

void	reverse_rot_ab(t_stack *stack)
{
	reverse_rot_a(stack);
	reverse_rot_b(stack);
	ft_printf("rrr\n");
}
