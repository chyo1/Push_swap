/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_make_asc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:55:58 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 12:22:14 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_2(t_node **a, t_node **b)
{
	t_node	*start;
	t_node	*sec;

	start = *a;
	sec = (*a)->next;
	if (start->val < sec->val)
		swap(*a, *b, 'a');

	push_b(a, b);
	(*b)->start = TRUE;

	push_b(a, b);
	(*b)->end = TRUE;
}

void	asc_3(t_node **a, t_node **b, int is_start)
{
	t_node	*fir;
	t_node	*sec;
	t_node	*thi;
	int		i;
	int		flag;

	fir = *a;
	sec = fir->next;
	thi = fir->pre;
	i = -1;

	// a b c / a c b / b c a --> b a c / c a b / c b a
	if (fir->val < sec->val)
		swap(*a, *b, 'a');

	if (fir->val < thi->val && sec->val < thi->val)
		flag = 0;
	else if (thi->val < fir->val && thi->val < sec->val)
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

void	asc_4(t_node **a, t_node **b, int is_start)
{
	int	n[4];

	n[0] = (*a)->val; // start
	n[1] = ((*a)->next)->val; // sec
	n[2] = (((*a)->next)->next)->val; // third
	n[3] = (*a)->pre->val;// end

	if (n[1] < n[0] && n[2] < n[0] && n[3] < n[0])
		push_b(a, b);
	else if (n[0] < n[1] && n[2] < n[1] && n[3] < n[1])
	{
		swap(*a, *b, 'a');
		push_b(a, b);
	}
	else if (n[0] < n[3] && n[1] < n[3] && n[2] < n[3])
	{
		reverse_rotate(a, b, 'a');
		push_b(a, b);
		rotate(a, b, 'a');
	}
	else
	{
		rotate(a, b, 'a');
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	if (is_start == TRUE)
		(*b)->start = TRUE;

	asc_3(a, b, FALSE);
}

void	asc_5(t_node **a, t_node **b)
{
	int	n[5];

	n[0] = (*a)->val; // start
	n[1] = ((*a)->next)->val; // sec
	n[2] = (((*a)->next)->next)->val; // third
	n[3] = ((*a)->pre)->val; // end
	n[4] = (((*a)->pre)->pre)->val; // pre-end

	if (n[1] < n[0] && n[2] < n[0] && n[3] < n[0] && n[4] < n[0])
	{
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	else if (n[0] < n[1] && n[2] < n[1] && n[3] < n[1] && n[4] < n[1])
	{
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	else if (n[0] < n[2] && n[1] < n[2] && n[3] < n[2] && n[4] < n[2])
	{
		rotate(a, b, 'a');
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
	}
	else if (n[0] < n[3] && n[1] < n[3] && n[2] < n[3] && n[4] < n[3])
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
	asc_4(a, b, FALSE);
}
