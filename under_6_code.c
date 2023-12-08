/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_6_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:01:42 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 12:25:33 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_node *a, t_node *b, int cnt)
{
	if (cnt == 2)
		order_2(a);
	else if (cnt == 3)
		return (order_3(a, b));
	else if (cnt == 4)
		return (order_4(a, b));
	else if (cnt == 5)
		return (order_5(a, b));
}

void	order_2(t_node *a)
{
	t_node	*start;
	t_node	*sec;

	start = a;
	sec = start->next;
	if (start->val > sec->val)
		swap_a(a);
}

void	order_3(t_node *a, t_node *b)
{
	int	fir;
	int	sec;
	int	thi;

	fir = a->val;
	sec = a->next->val;
	thi = a->pre->val;

	if (fir < sec)
	{
		// a c b  b c a
		if (thi < sec)
		{
			// a c b
			if (fir < thi)
			{
				swap_a(a);
				rotate(&a, &b, 'a');
			}

			// b c a
			else
				reverse_rotate(&a, &b, 'a');
		}
	}
	else // sec < fir
	{
		// b a c  c a b
		if (sec < thi)
		{
			// b a c
			if (fir < thi)
				swap_a(a);

			// c a b
			else
				rotate(&a, &b, 'a');
		}
		// thi < sec < fir
		else
		{
			swap_a(a);
			reverse_rotate(&a, &b, 'a');
		}

	}
}

void	order_4(t_node *a, t_node *b)
{
	int	n[4];

	n[0] = a->val; // start
	n[1] = (a->next)->val; // sec
	n[2] = ((a->next)->next)->val; // third
	n[3] = a->pre->val;// end
	if (n[1] < n[0] && n[2] < n[0] && n[3] < n[0])
		;
	else if (n[0] < n[1] && n[2] < n[1] && n[3] < n[1])
		swap(a, b, 'a');
	else if (n[0] < n[3] && n[1] < n[3] && n[2] < n[3])
		reverse_rotate(&a, &b, 'a');
	else
	{
		rotate(&a, &b, 'a');
		swap(a, b, 'a');
	}
	push_b(&a, &b);
	order_3(a, b);
}

void	order_5(t_node *a, t_node *b)
{
	int	n[5];

	n[0] = a->val; // start
	n[1] = (a->next)->val; // sec
	n[2] = ((a->next)->next)->val; // third
	n[3] = (a->pre)->val; // end
	n[4] = ((a->pre)->pre)->val; // pre-end

	if (n[1] < n[0] && n[2] < n[0] && n[3] < n[0] && n[4] < n[0])
		;
	else if (n[0] < n[1] && n[2] < n[1] && n[3] < n[1] && n[4] < n[1])
		swap(a, b, 'a');
	else if (n[0] < n[2] && n[1] < n[2] && n[3] < n[2] && n[4] < n[2])
	{
		rotate(&a, &b, 'a');
		swap(a, b, 'a');
	}
	else if (n[0] < n[3] && n[1] < n[3] && n[2] < n[3] && n[4] < n[3])
		reverse_rotate(&a, &b, 'a');
	else
	{
		reverse_rotate(&a, &b, 'a');
		reverse_rotate(&a, &b, 'a');
	}
	push_b(&a, &b);
	order_4(a, b);
}

