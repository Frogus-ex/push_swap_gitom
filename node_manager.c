/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:02:50 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/24 16:43:41 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_node **back, t_node *new)
{
	if (!back || !new)
		return ;
	if (*back == NULL)
	{
		*back = new;
		return ;
	}
	else
		ft_lstlast(*back)->next = new;
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
