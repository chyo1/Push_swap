/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_make_desc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:32:33 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/27 19:43:46 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	desc_2(t_node **a, t_node **b)
{
	t_node	*fir;
	t_node	*sec;
	
	fir = *a;
	sec = (*a)->next;
	
	if (sec->val < fir->val)
		swap_ab(*a, *b, 'a');
	push_b(a, b);
	push_b(a, b);
}

void	desc_3(t_node **a, t_node **b)
{
	t_node	*fir;
	t_node	*sec;
	t_node	*thi;
	int i;
	int flag;

	fir = *a;
	sec = fir->next;
	thi = fir->pre;
	i = -1;
	// a b c / a c b / b c a --> b a c / c a b / c b a
	if (sec->val < fir->val)
		swap_ab(*a, *b, 'a');
	if (fir->val < thi->val && sec->val < thi->val)
		flag = 2;
	else if (thi->val < fir->val && thi->val < sec->val)
		flag = 1;
	else
		flag = 0;
	while (++i < 3)
	{
		if (i == flag)
			reverse_rotate(a, b, 'a');
		push_b(a, b);
	}
}
void desc_4(t_node **a, t_node **b)
{
	t_node	*n[4];

	n[0] = *a;
	n[1] = n[0]->next;
	n[2] = n[1]->next;
	n[3] = n[0]->pre;
	if (n[0] < n[1] && n[0] < n[2] && n[0] < n[3])
		;
	else if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3])
		swap(*a, *b, 'a');
	else if (n[2] < n[0] && n[2] < n[1] && n[2] < n[3])
	{
		rotate(a, b, 'a');
		swap(*a, *b, 'a');
	}
	else
		reverse_rotate(a, b, 'a');
	desc_3(a, b);
}

void desc_5(t_node **a, t_node **b)
{
	t_node	*n[5];

	n[0] = *a;
	n[1] = n[0]->next;
	n[2] = n[1]->next;
	n[3] = n[0]->pre;
	n[4] = n[3]->pre;
	if (n[0] < n[1] && n[0] < n[2] && n[0] < n[3] && n[0] < n[4])
		;
	else if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3] && n[1] < n[4])
		swap(*a, *b, 'a');
	else if (n[2] < n[0] && n[2] < n[1] && n[2] < n[3] && n[2] < n[4])
	{
		rotate(a, b, 'a');
		swap(*a, *b, 'a');
	}
	else if (n[3] < n[0] && n[3] < n[1] && n[3] < n[2] && n[3] < n[4])
		reverse_rotate(a, b, 'a');
	else
	{
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
		swap(*a, *b, 'a');
	}
	desc_4(a, b);
}
