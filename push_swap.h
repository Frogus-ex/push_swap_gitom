/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:23:50 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/16 14:02:29 by tlorette         ###   ########.fr       */
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
int		main(void);
void	swap_stack(t_node **stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ss(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_stack(t_node **stack);
void	rotate_ab(t_stack *stack);

#endif
