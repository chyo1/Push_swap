/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_make_tri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:55:58 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/27 15:41:54 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cnt_2(t_node **a, t_node **b)
{
	t_node	*fir;
	t_node	*sec;
	
	fir = *a;
	sec = (*a)->next;
	
	if (fir->val < sec->val)
	{
		swap_ab(*a, *b, 'a');
		push_b(a, b);
		push_b(a, b);
	}
	else
	{
		push_b(a, b);
		push_b(a, b);
	}
}

void	cnt_3(t_node **a, t_node **b)
{
	t_node	*fir;
	t_node	*sec;
	t_node	*thi;

	fir = *a;
	sec = fir->next;
	thi = sec->next;
	// a b,c
	if (fir->val < sec->val && fir->val < thi->val)
	{
		rotate(a, b, 'a');
		if (sec->val < thi->val)
			swap_ab(*a, *b, 'a');
		push(a, b, 'b');
		push(a, b, 'b');
		reverse_rotate(a, b, 'c');
		push(a, b, 'b');
	}
	// c a,b
	else if (fir->val > sec->val && fir->val > thi->val)
	{
		push(a, b, 'b');
		if (sec->val < thi->val)
			swap_ab(*a, *b, 'a');
		push(a, b, 'b');
		push(a, b, 'b');
	}
	// b a,c
	else
	{
		rotate(a, b, 'a');
		if (sec->val < thi->val)
			swap_ab(*a, *b, 'a');
		push(a, b, 'b');
		reverse_rotate(a, b, 'a');
		push(a, b, 'b');
		push(a, b, 'b');
	}
}
void 3