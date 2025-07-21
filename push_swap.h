/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:23:50 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/21 19:15:27 by tlorette         ###   ########.fr       */
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
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
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
int		get_chunk_size(int size);
int		*tab_copy(t_node *stack, int *size_a);
void	tab_tri(int	*tab, int *size_a);
void	give_index(t_node *stack, int *tab, int *size_a);
void	get_chunk(t_stack *stack, int min, int max);
int		has_chunk(t_node *stack, int min, int max);
int		get_chunk_pos(t_node *stack, int min, int max);
int		get_max_pos(t_node *b);
void	push_b_in_a(t_stack *stack);
void	greedy_sort(t_stack *stack);
int		is_numerique(char *str);
void	add_node_back(t_node **back, t_node *new);
int		parse_input(char **av, t_stack *stack);
t_node	*ft_lstlast(t_node *lst);
void	ft_error(t_stack *stack, char *str);
int		ft_atol(t_stack *stack, const char *str);
char	*join_ps(char **av);


#endif
