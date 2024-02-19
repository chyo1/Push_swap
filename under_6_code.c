/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_6_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:01:42 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 20:08:06 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order(t_node *a, t_node *b, int cnt)
{
	if (cnt == 2)
		order_2(a, b);
	else if (cnt == 3)
		order_3(a, b);
	else if (cnt == 4)
		order_4(a, b);
	else if (cnt == 5)
		order_5(a, b);
	return (0);
}

void	order_2(t_node *a, t_node *b)
{
	t_node	*start;
	t_node	*sec;

	start = a;
	sec = start->next;
	if (start->val > sec->val)
		swap(a, b, 'a');
}

void	order_3(t_node *a, t_node *b)
{
	int	fir;
	int	sec;
	int	thi;

	fir = a->val;
	sec = a->next->val;
	thi = a->pre->val;
	if (fir < sec && fir < thi && thi < sec)
	{
		swap(a, b, 'a');
		rotate(&a, &b, 'a');
	}
	else if (fir < sec && thi < sec && thi < fir)
		reverse_rotate(&a, &b, 'a');
	else if (sec < fir && sec < thi && fir < thi)
		swap(a, b, 'a');
	else if (sec < fir && sec < thi && thi < fir)
		rotate(&a, &b, 'a');
	else if (thi < sec && thi < fir && sec < fir)
	{
		swap(a, b, 'a');
		reverse_rotate(&a, &b, 'a');
	}
}

void	order_4(t_node *a, t_node *b)
{
	int	n[4];

	n[0] = a->val;
	n[1] = (a->next)->val;
	n[2] = ((a->next)->next)->val;
	n[3] = a->pre->val;
	if (n[0] < n[1] && n[0] < n[2] && n[0] < n[3])
		;
	else if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3])
		swap(a, b, 'a');
	else if (n[3] < n[0] && n[3] < n[1] && n[3] < n[2])
		reverse_rotate(&a, &b, 'a');
	else
	{
		rotate(&a, &b, 'a');
		swap(a, b, 'a');
	}
	push_b(&a, &b);
	order_3(a, b);
	push_a(&a, &b);
}

void	order_5(t_node *a, t_node *b)
{
	int	n[5];

	n[0] = a->val;
	n[1] = (a->next)->val;
	n[2] = ((a->next)->next)->val;
	n[3] = (a->pre)->val;
	n[4] = ((a->pre)->pre)->val;
	if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3] && n[1] < n[4])
		swap(a, b, 'a');
	else if (n[2] < n[0] && n[2] < n[1] && n[2] < n[3] && n[2] < n[4])
	{
		rotate(&a, &b, 'a');
		swap(a, b, 'a');
	}
	else if (n[3] < n[0] && n[3] < n[1] && n[3] < n[2] && n[3] < n[4])
		reverse_rotate(&a, &b, 'a');
	else if (n[4] < n[0] && n[4] < n[1] && n[4] < n[2] && n[4] < n[3])
	{
		reverse_rotate(&a, &b, 'a');
		reverse_rotate(&a, &b, 'a');
	}
	push_b(&a, &b);
	order_4(a, b);
	push_a(&a, &b);
}
