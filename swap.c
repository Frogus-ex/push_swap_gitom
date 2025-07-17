/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:44:11 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/17 14:45:50 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack)->next || !*stack)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap_a(t_node **stack)
{
	swap_stack(stack);
	ft_printf("sa\n");
}

void	swap_b(t_node **stack)
{
	swap_stack(stack);
	ft_printf("sb\n");
}

void	swap_ss(t_node **a, t_node **b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
}
