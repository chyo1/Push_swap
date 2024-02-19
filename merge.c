/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:43:31 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 15:19:28 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(t_node **a, t_node **b, int tri_size, int tri_cnt)
{
	if (tri_size < 6)
		return ;
	else if (tri_size == 53 && tri_cnt == 1)
	{
		merge_to_a(a, b, 3);
		merge_to_b(a, b, 1);
		return ;
	}
	merge(a, b, tri_size / 3, tri_cnt * 3);
	if (*a == NULL)
		merge_to_a(a, b, tri_cnt);
	else
		merge_to_b(a, b, tri_cnt);
}

void	merge_to_a(t_node **a, t_node **b, int tri_cnt)
{
	int	cnt;

	cnt = 0;
	while (tri_cnt != cnt)
	{
		if ((*b)->start == TRUE)
			cnt++;
		push_a(a, b);
	}
	while (cnt > 0)
	{
		if ((*a)->pre->pre->val < (*a)->pre->val)
			asc_to_a(a, b);
		else
			desc_to_a(a, b);
		cnt--;
	}
	reverse_list_flag(*a);
}

void	merge_to_b(t_node **a, t_node **b, int tri_cnt)
{
	int	cnt;

	cnt = 0;
	while (tri_cnt != cnt)
	{
		if ((*a)->start == TRUE)
			cnt++;
		push_b(a, b);
	}
	while (cnt > 0)
	{
		if ((*b)->pre->pre->val < (*b)->pre->val)
			asc_to_b(a, b);
		else
			desc_to_b(a, b);
		cnt--;
	}
	reverse_list_flag(*b);
}

void	reverse_list_flag(t_node *head)
{
	t_node	*now;

	now = head;
	if (head == NULL)
		return ;
	while (now->next != head)
	{
		reverse_flag(now);
		now = now->next;
	}
	reverse_flag(now);
}

void	reverse_flag(t_node *now)
{
	if (now->start == TRUE)
	{
		now->start = FALSE;
		now->end = TRUE;
	}
	else if (now->end == TRUE)
	{
		now->end = FALSE;
		now->start = TRUE;
	}
}
