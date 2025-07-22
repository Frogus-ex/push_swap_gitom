/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:08:06 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/22 18:53:20 by tlorette         ###   ########.fr       */
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

void	reverse_rot_a(t_node **stack)
{
	reverse_rot_stack(stack);
	write(1, "rra\n", 4);
}

void	reverse_rot_b(t_node **stack)
{
	reverse_rot_stack(stack);
	write(1, "rrb\n", 4);
}

void	reverse_rot_ab(t_node **a, t_node **b)
{
	reverse_rot_a(a);
	reverse_rot_b(b);
	write(1, "rrr\n", 4);
}
