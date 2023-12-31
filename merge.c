/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:43:31 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 12:07:43 by hyowchoi         ###   ########.fr       */
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
	// move num 1/3 to a
	while (tri_cnt != cnt)
	{
		if ((*b)->start == TRUE)
			cnt++;
		push_a(a, b);
	}
	// printf("\n--------merge_to_a, div_to_b--------\n");
	// printf("\n        a\n");
	// print_rev_list(*a);
	// printf("\n        b\n");
	// print_list(*b);
	while (cnt > 0)
	{
		// check order
		if ((*a)->pre->pre->val < (*a)->pre->val) // asc
			asc_to_a(a, b);
		else // desc
			desc_to_a(a, b);
		cnt--;
	}
	reverse_list_flag(*a);
	// printf("\n--------merge_to_a--------\n");
	// print_list(*a);
	// print_list(*b);
}

void	merge_to_b(t_node **a, t_node **b, int tri_cnt)
{
	int	cnt;

	cnt = 0;
	// move to b
	while (tri_cnt != cnt)
	{
		if ((*a)->start == TRUE)
			cnt++;
		push_b(a, b);
	}
	// printf("\n--------merge_to_b, div_to_a--------\n");
	// printf("\n          a\n");
	// print_list(*a);
	// printf("\n          b\n");
	// print_rev_list(*b);
	while (cnt > 0)
	{
		// check order
		if ((*b)->pre->pre->val < (*b)->pre->val) // asc
			asc_to_b(a, b);
		else // desc
			desc_to_b(a, b);
		cnt--;
	}
	reverse_list_flag(*b);
	// printf("--------merge_to_b--------\n");
	// // print_list(*a);
	// print_list(*b);
}

void	reverse_list_flag(t_node *head)
{
	t_node	*now;

	now = head;
	if (head == NULL)
		return ;
	while (now->next != head)
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
		now = now->next;
	}

	// last node
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
