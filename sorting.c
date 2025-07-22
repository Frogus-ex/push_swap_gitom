/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:56:36 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/22 11:35:41 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->value;
	b = stack->a->next->value;
	c = stack->a->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a > b && b < c && a < c)
		swap_a(&stack->a);
	else if (a > b && b > c)
	{
		swap_a(&stack->a);
		reverse_rot_a(&stack->a);
	}
	else if (a < c && b > c && a < c)
	{
		reverse_rot_a(&stack->a);
		swap_a(&stack->a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(&stack->a);
	else if (a < b && b > c && a > c)
		reverse_rot_a(&stack->a);
}

void	sort_five_four(t_stack	*stack)
{
	if (!stack)
		return ;
	if (ps_lstsize(stack->a) < 6)
	{
		while (ps_lstsize(stack->a) > 2)
		{
			get_min_front(&stack->a);
			push_b(stack);
		}
		if (ps_lstsize(stack->a) && (stack->a->value > stack->a->next->value))
			swap_a(&stack->a);
		while (stack->b)
			push_a(stack);
	}
}
