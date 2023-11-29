/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:25:29 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/29 14:53:20 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asc_to_a(t_node **a, t_node **b)
{
	long long	num[3];

	num[0] = (*a)->pre->val; // last_a
	num[1] = (*b)->val; // first_b
	num[2] = (*b)->pre->val; // last_b
	while (1)
	{
		if ((*a)->pre->is_last == TRUE)
			num[0] = INT_MIN;
		if ((*b)->is_last == TRUE)
			num[1] = INT_MIN;
		if ((*b)->pre->is_last == TRUE)
			num[2] = INT_MIN;
		if (num[0] == num[1] && num[1] == num[2])
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
	}
	// check last val
	num[0] = (*a)->pre->val; // last_a
	num[1] = (*b)->val; // first_b
	num[2] = (*b)->pre->val; // last_b
	if (num[1] < num[0] && num[2] < num[0])
	{	
		reverse_rotate(a, b, 'a');
		if (num[1] < num[2]) // b c a
		{
			reverse_rotate(a, b, 'b');
			push_a(a, b);
			push_a(a, b);
		}
		else // c b a
		{
			push_a(a, b);
			reverse_rotate(a, b, 'b');
			push_a(a, b);
		}
	}
	else if (num[0] < num[1] && num[2] < num[1])
	{
		push_a(a, b);
		if (num[0] < num[2]) // a c b
		{
			reverse_rotate(a, b, 'b');
			push_a(a, b);
			push_a(a, b);
		}
		else // c a b
		{
			reverse_rotate(a, b, 'a');
			reverse_rotate(a, b, 'b');
			push_a(a, b);
		}
	}
	else if (num[0] < num[2] && num[1] < num[2])
	{
		reverse_rotate(a, b, 'b');
		push_a(a, b);
		if (num[0] < num[1]) // a b c
		{
			push_a(a, b);
			reverse_rotate(a, b, 'a');
		}
		else // b a c
		{
			reverse_rotate(a, b, 'a');
			push_a(a, b);
		}
	}
	(*a)->pre->is_last = FALSE;
	(*b)->is_last = FALSE;
	(*b)->pre->is_last = FALSE;
	(*a)->is_last = TRUE;
}

void	desc_to_a(t_node **a, t_node **b)
{
	long long	num[3];

	num[0] = (*a)->pre->val; // last_a
	num[1] = (*b)->val; // first_b
	num[2] = (*b)->pre->val; // last_b
	while (1)
	{
		if ((*a)->pre->is_last == TRUE)
			num[0] = INT_MAX;
		if ((*b)->is_last == TRUE)
			num[1] = INT_MAX;
		if ((*b)->pre->is_last == TRUE)
			num[2] = INT_MAX;
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
	// check last val
	num[0] = (*a)->pre->val; // last_a
	num[1] = (*b)->val; // first_b
	num[2] = (*b)->pre->val; // last_b
	if (num[0] < num[1] && num[0] < num[2])
	{	
		reverse_rotate(a, b, 'a');
		if (num[1] < num[2]) // a b c
		{
			push_a(a, b);
			reverse_rotate(a, b, 'b');
		}
		else // a c b
		{
			reverse_rotate(a, b, 'b');
			push_a(a, b);
		}
		push_a(a, b);
	}
	else if (num[1] < num[0] && num[1] < num[2])
	{
		push_a(a, b);
		reverse_rotate(a, b, 'b');
		if (num[0] < num[2]) // b a c
		{
			reverse_rotate(a, b, 'a');
			push_a(a, b);
		}
		else // b c a
		{
			push_a(a, b);
			reverse_rotate(a, b, 'a');
		}
	}
	else if (num[2] < num[0] && num[2] < num[1])
	{
		reverse_rotate(a, b, 'b');
		push_a(a, b);
		if (num[0] < num[1]) // c a b
		{
			reverse_rotate(a, b, 'a');
			push_a(a, b);
		}
		else // c b a
		{
			push_a(a, b);
			reverse_rotate(a, b, 'a');
		}
	}
	(*a)->pre->is_last = FALSE;
	(*b)->is_last = FALSE;
	(*b)->pre->is_last = FALSE;
	
	(*a)->is_last = TRUE;
}
