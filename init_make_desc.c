/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_make_desc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:32:33 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/30 20:14:10 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	desc_12(t_node **a, t_node **b, int cnt)
{
	t_node	*start;
	t_node	*sec;

	if (cnt == 1)
	{
		push_b(a, b);
		(*b)->start = TRUE;
		(*b)->end = TRUE;
		return ;
	}
	start = *a;
	sec = (*a)->next;
	
	if (sec->val < start->val)
		swap(*a, *b, 'a');
	push_b(a, b);
	(*b)->start = TRUE;
	push_b(a, b);
	(*b)->end = TRUE;
}

void	desc_3(t_node **a, t_node **b, int is_start)
{
	t_node	*start;
	t_node	*sec;
	t_node	*thi;
	int i;
	int flag;

	start = *a;
	sec = start->next;
	thi = start->pre;
	i = -1;
	// b a c / c a b / c b a --> a b c / a c b / b c a
	if (sec->val < start->val)
		swap(*a, *b, 'a');
	if (thi->val < start->val && thi->val < sec->val)
		flag = 0;
	else if (start->val < thi->val && sec->val < thi->val)
		flag = 2;
	else
		flag = 1;
	while (++i < 3)
	{
		if (i == flag)
			reverse_rotate(a, b, 'a');
		push_b(a, b);
		if (is_start == TRUE && i == 0)
			(*b)->start = TRUE;
	}
	(*b)->end = TRUE;
}

void	desc_4(t_node **a, t_node **b, int is_start)
{
	int	n[4];

	n[0] = (*a)->val; // start
	n[1] = ((*a)->next)->val; // sec
	n[2] = (((*a)->next)->next)->val; // third
	n[3] = ((*a)->pre)->val; // end
	if (n[0] < n[1] && n[0] < n[2] && n[0] < n[3])
		push_b(a, b);
	else if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3])
	{
		swap(*a, *b, 'a');
		push_b(a, b);
	}
	else if (n[2] < n[0] && n[2] < n[1] && n[2] < n[3])
	{
		rotate(a, b, 'a');
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	else
	{
		reverse_rotate(a, b, 'a');
		push_b(a, b);
		rotate(a, b, 'a');
	}
	if (is_start == TRUE)
		(*b)->start = TRUE;
	desc_3(a, b, FALSE);
}

void	desc_5(t_node **a, t_node **b)
{
	int	n[5];

	n[0] = (*a)->val; // start
	n[1] = ((*a)->next)->val; // sec
	n[2] = (((*a)->next)->next)->val; // third
	n[3] = ((*a)->pre)->val; // end
	n[4] = (((*a)->pre)->pre)->val; // pre-end
	if (n[0] < n[1] && n[0] < n[2] && n[0] < n[3] && n[0] < n[4])
	{
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	else if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3] && n[1] < n[4])
	{
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	else if (n[2] < n[0] && n[2] < n[1] && n[2] < n[3] && n[2] < n[4])
	{
		rotate(a, b, 'a');
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
	}
	else if (n[3] < n[0] && n[3] < n[1] && n[3] < n[2] && n[3] < n[4])
	{
		reverse_rotate(a, b, 'a');
		push_b(a, b);
	}
	else
	{
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
		push_b(a, b);
		rotate(a, b, 'a');
	}
	(*b)->start = TRUE;
	desc_4(a, b, FALSE);
}
