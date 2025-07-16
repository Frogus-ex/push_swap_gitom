/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:44:11 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/16 12:59:45 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	swap_stack(&stack->a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	swap_stack(&stack->b);
	ft_printf("sb\n");
}

void	swap_ss(t_stack *stack)
{
	swap_stack(&stack->a);
	swap_stack(&stack->b);
	ft_printf("ss\n");
}
