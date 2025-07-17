/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:23:50 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/17 17:36:07 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
	int				size_a;
	int				size_b;
}	t_stack;

t_node	*create_node(int value);
void	add_node_front(t_node **head, t_node *new);
int		ps_lstsize(t_node *node);
void	free_stack(t_node **stack);
void	print_stack(t_node *stack);
int		main(int ac, char **av);
void	swap_stack(t_node **stack);
void	swap_a(t_node **stack);
void	swap_b(t_node **stack);
void	swap_ss(t_node **a, t_node **b);
void	push_a(t_node **a, t_node **b);
void	push_b(t_node **b, t_node **a);
void	rotate_a(t_node **stack);
void	rotate_b(t_node **stack);
void	rotate_stack(t_node **stack);
void	rotate_ab(t_node **a, t_node **b);
void	reverse_rot_stack(t_node **stack);
int		get_min_pos(t_node *stack);
int		get_min_value(t_node *stack);
void	get_min_front(t_node **stack);
void	reverse_rot_a(t_node **stack);
void	reverse_rot_b(t_node **stack);
void	reverse_rot_ab(t_node **a, t_node **b);
void	sort_five_four(t_stack	*stack);
void	sort_three(t_stack *stack);

#endif
