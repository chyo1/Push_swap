/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_connect_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:13 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/27 12:40:58 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_node(t_node **root, int val)
{
	t_node	*new;
	t_node	*last;

	last = *root;
	while (last != NULL)
	{
		if (last->val == val)
			return (-1); // num duplicated
		if (last->next == NULL)
			break ;
		last = last->next;
	}
	new = (t_node *)malloc(sizeof(t_node *));
	if (new == NULL)
		return (-1); // malloc error
	new->val = val;
	new->is_last = 0;
	new->next = NULL;
	last->next = new;
}

void free_list(t_node **root)
{
	t_node	*del;
	t_node	*now;

	now = *root;
	del = *root;
	while (now)
	{
		del = now;
		now = now->next;
		free(del);
	}
}
