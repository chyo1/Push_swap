/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excep_desc_merge_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:38:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/05 18:34:01 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	excep_desc_to_b(t_node **a, t_node **b, int which)
{
	int	num[3];
	int	flag[3];

	flag[0] = flag[1] = flag[2] = 0;
	del_flag_excep((*b)->pre, *a, FIR, which);
	while (*a)
	{
		num[0] = (*b)->pre->val; 	// end_b -> f
		num[1] = (*a)->val; 		// fir_a -> f
		num[2] = (*a)->pre->val; 	// end_a -> e
		if (flag[0] >= 2) // end_b -> end
			num[0] = INT_MAX;
		if (flag[1] >= 2) // fir_a -> end
			num[1] = INT_MAX;
		if (flag[2] >= 2) // end_a -> start
			num[2] = INT_MAX;
		del_flag_excep((*b)->pre, *a, MID, which);
		if (num[0] == INT_MAX && num[1] == INT_MAX && num[2] == INT_MAX)
			break ;
		if (num[0] < num[1] && num[0] < num[2])
		{
			reverse_rotate(a, b, 'b');
			if (!flag[0] && !flag[1] && !flag[2])
				(*b)->end = TRUE;
			flag[0]++;
		}
		else if (num[1] < num[0] && num[1] < num[2])
		{
			push_b(a, b);
			if (!flag[0] && !flag[1] && !flag[2])
				(*b)->end = TRUE;
			flag[1]++;
		}
		else
		{
			reverse_rotate(a, b, 'a');
			push_b(a, b);
			if (!flag[0] && !flag[1] && !flag[2])
				(*b)->end = TRUE;
			flag[2]++;
		}
	}
	while (flag[0]++ < 2)
		reverse_rotate(a, b, 'b');
	(*b)->start = TRUE;
}

void	del_flag_excep(t_node *end_b, t_node *fir_a, int flag, int which)
{
	t_node	*end_a;
	
	end_a = fir_a->pre;
	if (flag == FIR)
	{
		end_b->end = FALSE;
		fir_a->end = FALSE;
		end_a->start = FALSE;
	}
	else if (flag == MID)
	{
		if (which == 16)
		{
			if (end_b->start == TRUE && end_b->pre->start == TRUE)
				end_b->start = FALSE;
			if (fir_a->start == TRUE)
				fir_a->start = FALSE;
			if (end_a->end == TRUE)
				end_a->end = FALSE;
		}
		else
		{
			if (end_b->start == TRUE && end_b->pre->start == TRUE) // 53 ㅇㅖ오ㅣ처리 하기, pre->end == true
				end_b->start = FALSE;
			if ((fir_a->start == TRUE) && (fir_a->next->start == FALSE && fir_a->next->end == FALSE))
				fir_a->start = FALSE;
			if ((end_a->end == TRUE) && (end_a->pre->start == FALSE && end_a->pre->end == FALSE))
				end_a->end = FALSE;
		}
	}
}
