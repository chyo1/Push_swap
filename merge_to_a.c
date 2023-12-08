/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:25:29 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/05 12:47:22 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_to_a(t_node **a, t_node **b)
{
	long long	num[3];
	int			flag;

	flag = 0;
	del_flag_a((*a)->pre, *b, (*b)->pre, FIR);
	while (*b)
	{
		num[0] = (*a)->pre->val; 	// end_a -> f
		num[1] = (*b)->val; 		// fir_b -> f
		num[2] = (*b)->pre->val; 	// end_b -> e

		// check node's loc, this node is in other triangle
		if ((*a)->pre->end == TRUE) // end_a -> end
			num[0] = INT_MIN;
		if ((*b)->end == TRUE) // fir_b -> end
			num[1] = INT_MIN;
		if ((*b)->pre->start == TRUE) // end_b -> start
			num[2] = INT_MIN;
		del_flag_a((*a)->pre, *b, (*b)->pre, MID);

		// finish merge
		if (num[0] == INT_MIN && num[1] == INT_MIN && num[2] == INT_MIN) // all node finished
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
		if (!flag)
		{
			flag = 1;
			// make end point
			(*a)->end = TRUE;
		}
	}

	// merge all node in triangle
	while((*a)->pre->end != TRUE)
		reverse_rotate(a, b, 'a');

	// make start point
	(*a)->start = TRUE;
}

void	desc_to_a(t_node **a, t_node **b)
{
	long long	num[3];
	int			flag;

	flag = 0;
	del_flag_a((*a)->pre, *b, (*b)->pre, FIR);
	while (*b)
	{
		num[0] = (*a)->pre->val; 	// end_a -> f
		num[1] = (*b)->val; 		// fir_b -> f
		num[2] = (*b)->pre->val; 	// end_b -> e
		if ((*a)->pre->end == TRUE) // end_a -> end
			num[0] = INT_MAX;
		if ((*b)->end == TRUE) // fir_b -> end
			num[1] = INT_MAX;
		if ((*b)->pre->start == TRUE) // end_b -> start
			num[2] = INT_MAX;
		del_flag_a((*a)->pre, *b, (*b)->pre, MID);
		if (num[0] == INT_MAX && num[1] == INT_MAX && num[2] == INT_MAX)
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
		if (!flag)
		{
			flag = 1;
			// make end point
			(*a)->end = TRUE;
		}
	}

	// merge all node in triangle
	while((*a)->pre->end != TRUE)
		reverse_rotate(a, b, 'a');

	// make start point
	(*a)->start = TRUE;
}

void	del_flag_a(t_node *end_a, t_node *fir_b, t_node *end_b, int flag)
{
	// start loc : delete all point
	if (flag == FIR)
	{
		end_a->end = FALSE;
		fir_b->end = FALSE;
		end_b->start = FALSE;
	}

	// while merging : delete points if the node is in triangle
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
