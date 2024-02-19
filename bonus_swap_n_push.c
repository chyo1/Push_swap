/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap_n_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/09 14:23:12 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swap(t_node *a, t_node *b, char which)
{
	if (which == 'a')
		swap_a(a);
	if (which == 'b')
		swap_b(b);
	if (which == 's')
	{
		swap_a(a);
		swap_b(b);
	}
	return (TRUE);
}

void	swap_a(t_node *a)
{
	t_node	*fir;
	t_node	*sec;
	int		tmp;

	if (a == NULL || a->next == NULL)
		return ;
	fir = a;
	sec = a->next;
	tmp = fir->val;
	fir->val = sec->val;
	sec->val = tmp;
	return ;
}

void	swap_b(t_node *b)
{
	t_node	*fir;
	t_node	*sec;
	int		tmp;

	if (b == NULL || b->next == NULL)
		return ;
	fir = b;
	sec = b->next;
	tmp = fir->val;
	fir->val = sec->val;
	sec->val = tmp;
	return ;
}

int	push_a(t_node **s1, t_node **s2)
{
	t_node	*node;

	node = pop_front(s2);
	if (node == NULL)
		return (TRUE);
	push_front(s1, node);
	return (TRUE);
}

int	push_b(t_node **s1, t_node **s2)
{
	t_node	*node;

	node = pop_front(s1);
	if (node == NULL)
		return (TRUE);
	push_front(s2, node);
	return (TRUE);
}
