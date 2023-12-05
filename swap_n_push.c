/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_n_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/05 13:19:12 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *a, t_node *b, char which)
{
	if (which == 'a' && swap_a(a) == 1)
		write(1, "sa\n", 3);
	if (which == 'b' && swap_b(b) == 1)
		write(1, "sb\n", 3);
	if (which == 'c' && (swap_a(a) == 1 || swap_b(b) == 1))
		write(1, "ss\n", 3);
}

int	swap_a(t_node *a)
{
	t_node		*fir;
	t_node		*sec;
	long long	tmp;

	if (a == NULL || a->next == NULL)
		return (0);
	fir = a;
	sec = a->next;
	tmp = fir->val;
	fir->val = sec->val;
	sec->val = tmp;
	return (1);
}

int	swap_b(t_node *b)
{
	t_node		*fir;
	t_node		*sec;
	long long	tmp;

	if (b == NULL || b->next == NULL)
		return (0);
	fir = b;
	sec = b->next;
	tmp = fir->val;
	fir->val = sec->val;
	sec->val = tmp;
	return (1);
}

void	push_a(t_node **s1, t_node **s2)
{
	t_node	*node;

	node = pop_front(s2);
	if (node == NULL)
		return ;
	push_front(s1, node);
	write(1, "pa\n", 3);
}

void	push_b(t_node **s1, t_node **s2)
{
	t_node	*node;

	node = pop_front(s1);
	if (node == NULL)
		return ;
	push_front(s2, node);
	write(1, "pb\n", 3);
}
