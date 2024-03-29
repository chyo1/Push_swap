/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:25:29 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 15:47:01 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_to_a(t_node **a, t_node **b)
{
	long long	num[3];
	int			flag;

	flag = TRUE;
	del_flag_a((*a)->pre, *b, (*b)->pre, FIR);
	while (*b)
	{
		if (check_tri_a(*a, *b, num, ASC) == -1)
			break ;
		if (num[1] < num[0] && num[2] < num[0])
			reverse_rotate(a, b, 'a');
		else if (num[0] < num[1] && num[2] < num[1])
			push_a(a, b);
		else
		{
			reverse_rotate(a, b, 'b');
			push_a(a, b);
		}
		(*a)->end = flag;
		if (flag == TRUE)
			flag = FALSE;
	}
	while ((*a)->pre->end != TRUE)
		reverse_rotate(a, b, 'a');
	(*a)->start = TRUE;
}

void	desc_to_a(t_node **a, t_node **b)
{
	long long	num[3];
	int			flag;

	flag = TRUE;
	del_flag_a((*a)->pre, *b, (*b)->pre, FIR);
	while (*b)
	{
		if (check_tri_a(*a, *b, num, DESC) == -1)
			break ;
		if (num[0] < num[1] && num[0] < num[2])
			reverse_rotate(a, b, 'a');
		else if (num[1] < num[0] && num[1] < num[2])
			push_a(a, b);
		else
		{
			reverse_rotate(a, b, 'b');
			push_a(a, b);
		}
		(*a)->end = flag;
		if (flag == TRUE)
			flag = FALSE;
	}
	while ((*a)->pre->end != TRUE)
		reverse_rotate(a, b, 'a');
	(*a)->start = TRUE;
}

void	del_flag_a(t_node *end_a, t_node *fir_b, t_node *end_b, int flag)
{
	if (flag == FIR)
	{
		end_a->end = FALSE;
		fir_b->end = FALSE;
		end_b->start = FALSE;
	}
	else if (flag == MID)
	{
		if (end_a->end != TRUE)
			end_a->start = FALSE;
		if (fir_b->end != TRUE)
			fir_b->start = FALSE;
		if (end_b->start != TRUE)
			end_b->end = FALSE;
	}
}

int	check_tri_a(t_node *a, t_node *b, long long num[], int which)
{
	long long	min_max;

	if (which == ASC)
		min_max = INT_MIN;
	else
		min_max = INT_MAX;
	num[0] = a->pre->val;
	num[1] = b->val;
	num[2] = b->pre->val;
	if (a->pre->end == TRUE)
		num[0] = min_max;
	if (b->end == TRUE)
		num[1] = min_max;
	if (b->pre->start == TRUE)
		num[2] = min_max;
	del_flag_a(a->pre, b, b->pre, MID);
	if (num[0] == min_max && num[1] == min_max && num[2] == min_max)
		return (-1);
	return (0);
}
