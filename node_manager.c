/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:02:50 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/21 13:03:54 by tlorette         ###   ########.fr       */
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

void	add_node_front(t_node **head, t_node *new)
{
	if (!new)
		return ;
	new->next = *head;
	*head = new;
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
