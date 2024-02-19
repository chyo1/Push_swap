/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_make_asc_or_desc_6.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:12:03 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 16:37:32 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_6(t_node **a, t_node **b)
{
	int	n[6];

	init_make_put_num(a, n, 6);
	if (n[1] < n[0] && n[2] < n[0] && n[3] < n[0] && n[4] < n[0] && n[5] < n[0])
	{
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	else if (n[0] < n[1] && n[2] < n[1] && n[3] < n[1] && n[4] < n[1] && n[5] < n[1])
	{
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	else if (n[0] < n[2] && n[1] < n[2] && n[3] < n[2] && n[4] < n[2] && n[5] < n[2])
		asc_6_do(a, b, 2);
	else if (n[0] < n[3] && n[1] < n[3] && n[2] < n[3] && n[4] < n[3] && n[5] < n[3])
		asc_6_do(a, b, 3);
	else if (n[0] < n[4] && n[1] < n[4] && n[2] < n[4] && n[3] < n[4] && n[5] < n[4])
		asc_6_do(a, b, 4);
	else
		asc_6_do(a, b, 5);
	(*b)->start = TRUE;
	asc_5(a, b, FALSE);
}

void	asc_6_do(t_node **a, t_node **b, int big_loc)
{
	if (big_loc == 2)
	{
		rotate(a, b, 'a');
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
	}
	else if (big_loc == 3)
	{
		reverse_rotate(a, b, 'a');
		push_b(a, b);
	}
	else if (big_loc == 4)
	{
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
		push_b(a, b);
		rotate(a, b, 'a');
	}
	else if (big_loc == 5)
	{
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
		push_b(a, b);
		rotate(a, b, 'a');
		rotate(a, b, 'a');
	}
}

void	desc_6(t_node **a, t_node **b)
{
	int	n[6];

	init_make_put_num(a, n, 6);
	if (n[0] < n[1] && n[0] < n[2] && n[0] < n[3] && n[0] < n[4] && n[0] < n[5])
	{
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	else if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3] && n[1] < n[4] && n[1] < n[5])
	{
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
	}
	else if (n[2] < n[0] && n[2] < n[1] && n[2] < n[3] && n[2] < n[4] && n[2] < n[5])
		desc_6_do(a, b, 2);
	else if (n[3] < n[0] && n[3] < n[1] && n[3] < n[2] && n[3] < n[4] && n[3] < n[5])
		desc_6_do(a, b, 3);
	else if (n[4] < n[0] && n[4] < n[1] && n[4] < n[2] && n[4] < n[3] && n[4] < n[5])
		desc_6_do(a, b, 4);
	else
		desc_6_do(a, b, 5);
	(*b)->start = TRUE;
	desc_5(a, b, FALSE);
}

void	desc_6_do(t_node **a, t_node **b, int small_loc)
{
	if (small_loc == 2)
	{
		rotate(a, b, 'a');
		swap(*a, *b, 'a');
		push_b(a, b);
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
	}
	else if (small_loc == 3)
	{
		reverse_rotate(a, b, 'a');
		push_b(a, b);
	}
	else if (small_loc == 4)
	{
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
		push_b(a, b);
		rotate(a, b, 'a');
	}
	else if (small_loc == 5)
	{
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
		reverse_rotate(a, b, 'a');
		push_b(a, b);
		rotate(a, b, 'a');
		rotate(a, b, 'a');
	}
}
