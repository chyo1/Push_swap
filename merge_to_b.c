/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:25:29 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/05 15:08:30 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_to_b(t_node **a, t_node **b)
{
	long long	num[3];
	int			flag;

	flag = 0;
	del_flag_b((*b)->pre, *a, (*a)->pre, FIR);
	while (*a)
	{
		num[0] = (*b)->pre->val; 	// end_b -> f
		num[1] = (*a)->val; 		// fir_a -> f
		num[2] = (*a)->pre->val; 	// end_a -> e
	
		// check node's loc, this node is in other triangle
		if ((*b)->pre->end == TRUE) // end_b -> end
			num[0] = INT_MIN;
		if ((*a)->end == TRUE) // fir_a -> end
			num[1] = INT_MIN;
		if ((*a)->pre->start == TRUE) // end_a -> start
			num[2] = INT_MIN;

		del_flag_b((*b)->pre, *a, (*a)->pre, MID);

		// finish merge
		if (num[0] == INT_MIN && num[1] == INT_MIN && num[2] == INT_MIN) // all node finished
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
		if (!flag)
		{
			flag = 1;
			// make end point
			(*b)->end = TRUE;
		}
	}

	// merge all node in triangle
	while((*b)->pre->end != TRUE)
		reverse_rotate(a, b, 'b');

	// make start point
	(*b)->start = TRUE;
}

void	desc_to_b(t_node **a, t_node **b)
{
	long long	num[3];
	int			flag;

	flag = 0;
	del_flag_b((*b)->pre, *a, (*a)->pre, FIR);
	while (*a)
	{
		num[0] = (*b)->pre->val; 	// end_b -> f
		num[1] = (*a)->val; 		// fir_a -> f
		num[2] = (*a)->pre->val; 	// end_a -> e
		if ((*b)->pre->end == TRUE) // end_b -> end
			num[0] = INT_MAX;
		if ((*a)->end == TRUE) // fir_a -> end
			num[1] = INT_MAX;
		if ((*a)->pre->start == TRUE) // end_a -> start
			num[2] = INT_MAX;
		del_flag_b((*b)->pre, *a, (*a)->pre, MID);
		if (num[0] == INT_MAX && num[1] == INT_MAX && num[2] == INT_MAX)
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
		if (!flag)
		{
			flag = 1;
			// make end point
			(*b)->end = TRUE;
		}
	}

	// merge all node in triangle
	while((*b)->pre->end != TRUE)
		reverse_rotate(a, b, 'b');
	
	// make start point
	(*b)->start = TRUE;
}

void	del_flag_b(t_node *end_b, t_node *fir_a, t_node *end_a, int flag)
{
	// start loc : delete all point
	if (flag == FIR)
	{
		end_b->end = FALSE;
		fir_a->end = FALSE;
		end_a->start = FALSE;
	}

	// while merging : delete points if the node is in triangle
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