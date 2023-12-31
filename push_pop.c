/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:34:18 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 12:06:17 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_node **head, t_node *new_node)
{
	if (*head == NULL)
	{
		*head = new_node;
		new_node->pre = *head;
		new_node->next = *head;
		return ;
	}
	else
	{
		new_node->pre = (*head)->pre;
		new_node->next = *head;
		(*head)->pre->next = new_node;
		(*head)->pre = new_node;
		*head = new_node;
	}
}

void	push_back(t_node **head, t_node *new_node)
{
	if (*head == NULL)
	{
		*head = new_node;
		new_node->pre = *head;
		new_node->next = *head;
		return ;
	}
	else
	{
		new_node->pre = (*head)->pre;
		new_node->next = *head;
		(*head)->pre->next = new_node;
		(*head)->pre = new_node;
	}
}

t_node	*pop_front(t_node **head)
{
	t_node	*ans;

	if (*head == NULL)
		return (NULL);
	if ((*head)->next == *head)
	{
		ans = *head;
		*head = NULL;
		return (ans);
	}
	ans = *head;
	(*head)->pre->next = (*head)->next;
	(*head)->next->pre = (*head)->pre;
	*head = (*head)->next;
	return (ans);
}

t_node	*pop_back(t_node **head)
{
	t_node	*ans;

	if (*head == NULL)
		return (NULL);
	if ((*head)->next == *head)
	{
		ans = *head;
		*head = NULL;
		return (ans);
	}
	ans = (*head)->pre;
	(*head)->pre->pre->next = *head;
	(*head)->pre = (*head)->pre->pre;
	return (ans);
}
