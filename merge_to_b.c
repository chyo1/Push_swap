/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:25:29 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 15:42:31 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_to_b(t_node **a, t_node **b)
{
	long long	num[3];
	int			flag;

	flag = TRUE;
	del_flag_b((*b)->pre, *a, (*a)->pre, FIR);
	while (*a)
	{
		if (check_tri_b(*a, *b, num, ASC) == -1)
			break ;
		if (num[1] < num[0] && num[2] < num[0])
			reverse_rotate(a, b, 'b');
		else if (num[0] < num[1] && num[2] < num[1])
			push_b(a, b);
		else
		{
			reverse_rotate(a, b, 'a');
			push_b(a, b);
		}
		(*b)->end = flag;
		if (flag == TRUE)
			flag = FALSE;
	}
	while ((*b)->pre->end != TRUE)
		reverse_rotate(a, b, 'b');
	(*b)->start = TRUE;
}

void	desc_to_b(t_node **a, t_node **b)
{
	long long	num[3];
	int			flag;

	flag = TRUE;
	del_flag_b((*b)->pre, *a, (*a)->pre, FIR);
	while (*a)
	{
		if (check_tri_b(*a, *b, num, DESC) == -1)
			break ;
		if (num[0] < num[1] && num[0] < num[2])
			reverse_rotate(a, b, 'b');
		else if (num[1] < num[0] && num[1] < num[2])
			push_b(a, b);
		else
		{
			reverse_rotate(a, b, 'a');
			push_b(a, b);
		}
		(*b)->end = flag;
		if (flag == TRUE)
			flag = FALSE;
	}
	while ((*b)->pre->end != TRUE)
		reverse_rotate(a, b, 'b');
	(*b)->start = TRUE;
}

void	del_flag_b(t_node *end_b, t_node *fir_a, t_node *end_a, int flag)
{
	if (flag == FIR)
	{
		end_b->end = FALSE;
		fir_a->end = FALSE;
		end_a->start = FALSE;
	}
	else if (flag == MID)
	{
		if (end_b->end != TRUE)
			end_b->start = FALSE;
		if (fir_a->end != TRUE)
			fir_a->start = FALSE;
		if (end_a->start != TRUE)
			end_a->end = FALSE;
	}
}

int	check_tri_b(t_node *a, t_node *b, long long num[], int which)
{
	long long	min_max;

	if (which == ASC)
		min_max = INT_MIN;
	else
		min_max = INT_MAX;
	num[0] = b->pre->val;
	num[1] = a->val;
	num[2] = a->pre->val;
	if (b->pre->end == TRUE)
		num[0] = min_max;
	if (a->end == TRUE)
		num[1] = min_max;
	if (a->pre->start == TRUE)
		num[2] = min_max;
	del_flag_b(b->pre, a, a->pre, MID);
	if (num[0] == min_max && num[1] == min_max && num[2] == min_max)
		return (-1);
	return (0);
}
