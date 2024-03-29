/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_connect_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:13 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/10 15:21:42 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_node(t_node **head, int val)
{
	t_node	*new_node;
	t_node	*last;

	last = *head;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (-1);
	new_node->val = val;
	new_node->start = FALSE;
	new_node->end = FALSE;
	while (*head != NULL)
	{
		if (last->val == val)
		{
			free(new_node);
			return (-1);
		}
		if (last->next == *head)
			break ;
		last = last->next;
	}
	push_back(head, new_node);
	return (0);
}

void	free_list(t_node **head)
{
	t_node	*del;
	t_node	*now;

	now = *head;
	del = *head;
	if (!(*head))
		return ;
	while (now->next != *head)
	{
		del = now;
		now = now->next;
		free(del);
	}
	free(now);
}
