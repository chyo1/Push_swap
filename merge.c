/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:43:31 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/29 18:32:07 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(t_node **a, t_node **b, int cnt[], int to_where)
{
	if (cnt[0] < 6)
		return ;
	cnt[0] /= 3;
	cnt[1] *= 3;
	if (to_where == TO_A)
	{
		merge(a, b, cnt, TO_B);
		merge_to_a(a, b, cnt[1]);
	}
	else
	{
		merge(a, b, cnt, TO_A);
		merge_to_b(a, b, cnt[1]);
	}
}

void	merge_to_a(t_node **a, t_node **b, int div)
{
	int	i;

	i = 0;
	// move to a
	while (1)
	{
		if ((*b)->is_last == TRUE)
		{
			i++;
			(*b)->is_last = FALSE;
			if (i != 1)
				(*a)->is_last = TRUE;
		}
		if (div / 3 < i)
			break;
		push_a(a, b);
	}
	while (i > 0)
	{
		// check order
		if ((*a)->val < (*a)->next->val) // asc
			asc_to_a(a, b);
		else // desc
			desc_to_a(a, b);
		i--;
	}
}

void	merge_to_b(t_node **a, t_node **b, int div)
{
	int	i;

	i = 0;
	// move to a
	while (1)
	{
		if ((*a)->is_last == TRUE)
		{
			i++;
			(*a)->is_last = FALSE;
			if (i != 1)
				(*b)->is_last = TRUE;
		}
		if (div / 3 < i)
			break;
		push_b(a, b);
	}
	while (i > 0)
	{
		// check order
		if ((*b)->val < (*b)->next->val) // asc
			asc_to_b(a, b);
		else // desc
			desc_to_b(a, b);
		i--;
	}
}
