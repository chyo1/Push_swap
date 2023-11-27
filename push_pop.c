/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:34:18 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/27 17:26:14 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_front(t_node **head, t_node *new)
{
	if (*head == NULL)
	{
		*head = new;
		new->pre = *head;
		new->next = *head;
		return ;
	}
	else
	{
		new->pre = (*head)->pre;
		(*head)->pre->next = new;
		new->next = *head;
		(*head)->pre = new;
		*head = new;
	}
}

void push_back(t_node **head, t_node *new)
{
	if (*head == NULL)
	{
		*head = new;
		new->pre = *head;
		new->next = *head;
		return ;
	}
	else
	{
		new->pre = (*head)->pre;
		(*head)->pre->next = new;
		new->next = *head;
		(*head)->pre = new;
	}
}

t_node	*pop_front(t_node **head)
{
	t_node	*ans;
	
	if (*head == NULL)
		return (NULL);
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
	ans = *head;
	(*head)->pre->next = (*head)->next;
	(*head)->next->pre = (*head)->pre;
	return (ans);
}
