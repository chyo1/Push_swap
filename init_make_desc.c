/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_make_desc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:32:33 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 16:20:28 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	desc_2(t_node **a, t_node **b)
{
	t_node	*start;
	t_node	*sec;

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
	int	n[3];
	int	i;
	int	flag;

	init_make_put_num(a, n, 3);
	i = -1;
	if (n[1] < n[0])
		swap(*a, *b, 'a');
	if (n[2] < n[0] && n[2] < n[1])
		flag = 0;
	else if (n[0] < n[2] && n[1] < n[2])
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

	init_make_put_num(a, n, 4);
	if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3])
		swap(*a, *b, 'a');
	else if (n[2] < n[0] && n[2] < n[1] && n[2] < n[3])
	{
		rotate(a, b, 'a');
		swap(*a, *b, 'a');
	}
	else if (n[3] < n[0] && n[3] < n[1] && n[3] < n[2])
		reverse_rotate(a, b, 'a');
	push_b(a, b);
	if (n[0] < n[1] && n[0] < n[2] && n[0] < n[3])
		;
	else if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3])
		;
	else if (n[2] < n[0] && n[2] < n[1] && n[2] < n[3])
		reverse_rotate(a, b, 'a');
	else
		rotate(a, b, 'a');
	if (is_start == TRUE)
		(*b)->start = TRUE;
	desc_3(a, b, FALSE);
}

void	desc_5(t_node **a, t_node **b, int is_start)
{
	int	n[5];

	init_make_put_num(a, n, 5);
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
		desc_5_do(a, b, 2);
	else if (n[3] < n[0] && n[3] < n[1] && n[3] < n[2] && n[3] < n[4])
		desc_5_do(a, b, 3);
	else
		desc_5_do(a, b, 4);
	if (is_start == TRUE)
		(*b)->start = TRUE;
	desc_4(a, b, FALSE);
}

void	desc_5_do(t_node **a, t_node **b, int small_loc)
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
}
