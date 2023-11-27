/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_connect_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:13 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/27 17:26:28 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_node(t_node **head, int val)
{
	t_node	*new;
	t_node	*last;

	last = *head;
	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (-1);
	new->val = val;
	if (*head == NULL)
	{
		push_back(head, new);
		return (0);
	}
	while (last != NULL)
	{
		if (last->val == val)
		{
			free(new);
			return (-1); // num duplicated
		}
		if (last->next == *head)
			break ;
		last = last->next;
	}
	push_back(head, new);
}

void free_list(t_node **head)
{
	t_node	*del;
	t_node	*now;

	now = *head;
	del = *head;
	while (now->next == *head)
	{
		del = now;
		now = now->next;
		free(del);
	}
}
