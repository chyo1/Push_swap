/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_n_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:55 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/23 11:12:43 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_last_node(t_node *node)
{
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	rotate(t_node **s1, t_node **s2, int which)
{
	t_node	*a_fir;
	t_node	*a_last;
	t_node	*b_fir;
	t_node	*b_last;

	if (*s1 && (which == 1 || which == 0))
	{
		a_fir = *s1;
		a_last = get_last_node(a_fir);
		*s1 = a_fir->next;
		a_last->next = a_fir;
		a_fir->next = NULL;
	}
	if (*s2 && (which == 2 || which == 0))
	{
		b_fir = *s2;
		b_last = get_last_node(b_fir);
		*s2 = b_fir->next;
		b_last->next = b_fir;
		b_fir->next = NULL;
	}
}

t_node	*get_prelast_node(t_node *node)
{
	t_node	*pre;
	t_node	*last;

	pre = node;
	last = node;
	while (last->next != NULL)
	{
		pre = last;
		last = last->next;
	}
	return (pre);
}

void	reverse_rotate(t_node **s1, t_node **s2, int which)
{
	t_node	*a_pre_last;
	t_node	*a_last;
	t_node	*b_pre_last;
	t_node	*b_last;

	if (*s1 && (which == 1 || which == 0))
	{
		a_pre_last = get_prelast_node(*s1);
		a_last = a_pre_last->next;
		a_last->next = *s1;
		*s1 = a_last;
		a_pre_last->next = NULL;
	}
	if (*s2 && (which == 2 || which == 0))
	{
		b_pre_last = get_prelast_node(*s1);
		b_last = b_pre_last->next;
		b_last->next = *s1;
		*s1 = b_last;
		b_pre_last->next = NULL;
	}
}
