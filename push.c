/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:02:58 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/16 13:26:20 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack)
{
	t_node	*node;

	if (!stack->b)
		return ;
	node = stack->b;
	stack->b = node->next;
	node->next = stack->a;
	stack->a = node;
	ft_printf("pa\n");
}


void	push_b(t_stack *stack)
{
	t_node	*node;

	if (!stack->a)
		return ;
	node = stack->a;
	stack->a = node->next;
	node->next = stack->b;
	stack->b = node;
	ft_printf("pb\n");
}
