/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:25:29 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/30 20:33:04 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_to_a(t_node **a, t_node **b)
{
	long long	num[3];
	int			flag;

	flag = 0;
	del_flag((*a)->pre, *b, (*b)->pre, FIR);
	while (*b)
	{
		num[0] = (*a)->pre->val; 	// end_a -> f
		num[1] = (*b)->val; 		// fir_b -> f
		num[2] = (*b)->pre->val; 	// end_b -> e
		if ((*a)->pre->end == TRUE) // end_a -> end
			num[0] = INT_MIN;
		if ((*b)->end == TRUE) // fir_b -> end
			num[1] = INT_MIN;
		if ((*b)->pre->start == TRUE) // end_b -> start
			num[2] = INT_MIN;
		del_flag((*a)->pre, *b, (*b)->pre, MID);
		if (num[0] == num[1] && num[1] == num[2]){ // all node finished
			break ;
		}
		if (num[1] < num[0] && num[2] < num[0])
			reverse_rotate(a, b, 'a');
		else if (num[0] < num[1] && num[2] < num[1])
			push_a(a, b);
		else
		{
			reverse_rotate(a, b, 'b');
			push_a(a, b);
		}
		if (!flag)
		{
			flag = 1;
			(*a)->end = TRUE;
		}
	}
	while((*a)->pre->end != TRUE)
		reverse_rotate(a, b, 'a');
	(*a)->start = TRUE;
}

void	del_flag(t_node *end_a, t_node *fir_b, t_node *end_b, int flag)
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

void	desc_to_a(t_node **a, t_node **b)
{
	long long	num[3];

	num[0] = (*a)->pre->val; 	// end_a -> f
	num[1] = (*b)->val; 		// start_b -> f
	num[2] = (*b)->pre->val; 	// end_b -> e
	del_flag((*a)->pre, *b, (*b)->pre, FIR);
	while (1)
	{
		if ((*a)->pre->end == TRUE) // end_a -> end
			num[0] = INT_MIN;
		if ((*b)->end == TRUE) // startst_b -> end
			num[1] = INT_MIN;
		if ((*b)->pre->start == TRUE) // end_b -> start
			num[2] = INT_MIN;
		del_flag((*a)->pre, *b, (*b)->pre, MID);
		if (num[0] == num[1] && num[1] == num[2])
			break ;
		if (num[0] < num[1] && num[0] < num[1])
			reverse_rotate(a, b, 'a');
		else if (num[1] < num[0] && num[1] < num[2])
			push_a(a, b);
		else
		{
			reverse_rotate(a, b, 'b');
			push_a(a, b);
		}
	}
}
