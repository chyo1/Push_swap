// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   merge_to_b.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/11/29 14:25:41 by hyowchoi          #+#    #+#             */
// /*   Updated: 2023/11/29 14:54:24 by hyowchoi         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void	asc_to_b(t_node **a, t_node **b)
// {
// 	long long	num[3];

// 	num[0] = (*b)->pre->val; // last_b
// 	num[1] = (*a)->val; // first_a
// 	num[2] = (*a)->pre->val; // last_a
// 	while (1)
// 	{
// 		if ((*b)->pre->is_last == TRUE)
// 			num[0] = INT_MIN;
// 		if ((*a)->is_last == TRUE)
// 			num[1] = INT_MIN;
// 		if ((*a)->pre->is_last == TRUE)
// 			num[2] = INT_MIN;
// 		if (num[0] == num[1] && num[1] == num[2])
// 			break ;
// 		if (num[1] < num[0] && num[2] < num[0])
// 			reverse_rotate(a, b, 'b');
// 		else if (num[0] < num[1] && num[2] < num[1])
// 			push_b(a, b);
// 		else
// 		{
// 			reverse_rotate(a, b, 'a');
// 			push_b(a, b);
// 		}
// 	}
// 	// check last val
// 	num[0] = (*b)->pre->val; // last_b
// 	num[1] = (*a)->val; // first_a
// 	num[2] = (*a)->pre->val; // last_a
// 	if (num[1] < num[0] && num[2] < num[0])
// 	{	
// 		reverse_rotate(a, b, 'b');
// 		if (num[1] < num[2]) // b c a
// 		{
// 			reverse_rotate(a, b, 'a');
// 			push_b(a, b);
// 			push_b(a, b);
// 		}
// 		else // c b a
// 		{
// 			push_b(a, b);
// 			reverse_rotate(a, b, 'a');
// 			push_b(a, b);
// 		}
// 	}
// 	else if (num[0] < num[1] && num[2] < num[1])
// 	{
// 		push_b(a, b);
// 		if (num[0] < num[2]) // a c b
// 		{
// 			reverse_rotate(a, b, 'a');
// 			push_b(a, b);
// 			push_b(a, b);
// 		}
// 		else // c a b
// 		{
// 			reverse_rotate(a, b, 'b');
// 			reverse_rotate(a, b, 'a');
// 			push_b(a, b);
// 		}
// 	}
// 	else if (num[0] < num[2] && num[1] < num[2])
// 	{
// 		reverse_rotate(a, b, 'a');
// 		push_b(a, b);
// 		if (num[0] < num[1]) // a b c
// 		{
// 			push_b(a, b);
// 			reverse_rotate(a, b, 'b');
// 		}
// 		else // b a c
// 		{
// 			reverse_rotate(a, b, 'b');
// 			push_b(a, b);
// 		}
// 	}
// 	(*b)->pre->is_last = FALSE;
// 	(*a)->is_last = FALSE;
// 	(*a)->pre->is_last = FALSE;
// 	(*b)->is_last = TRUE;
// }

// void	desc_to_b(t_node **a, t_node **b)
// {
// 	long long	num[3];

// 	num[0] = (*b)->pre->val; // last_b
// 	num[1] = (*a)->val; // first_a
// 	num[2] = (*a)->pre->val; // last_a
// 	while (1)
// 	{
// 		if ((*b)->pre->is_last == TRUE)
// 			num[0] = INT_MAX;
// 		if ((*a)->is_last == TRUE)
// 			num[1] = INT_MAX;
// 		if ((*a)->pre->is_last == TRUE)
// 			num[2] = INT_MAX;
// 		if (num[0] == num[1] && num[1] == num[2])
// 			break ;
// 		if (num[0] < num[1] && num[0] < num[1])
// 			reverse_rotate(a, b, 'b');
// 		else if (num[1] < num[0] && num[1] < num[2])
// 			push_b(a, b);
// 		else
// 		{
// 			reverse_rotate(a, b, 'a');
// 			push_b(a, b);
// 		}
// 	}
// 	// check last val
// 	num[0] = (*b)->pre->val; // last_b
// 	num[1] = (*a)->val; // first_a
// 	num[2] = (*a)->pre->val; // last_a
// 	if (num[0] < num[1] && num[0] < num[2])
// 	{	
// 		reverse_rotate(a, b, 'b');
// 		if (num[1] < num[2]) // a b c
// 		{
// 			push_b(a, b);
// 			reverse_rotate(a, b, 'a');
// 		}
// 		else // a c b
// 		{
// 			reverse_rotate(a, b, 'a');
// 			push_b(a, b);
// 		}
// 		push_b(a, b);
// 	}
// 	else if (num[1] < num[0] && num[1] < num[2])
// 	{
// 		push_b(a, b);
// 		reverse_rotate(a, b, 'a');
// 		if (num[0] < num[2]) // b a c
// 		{
// 			reverse_rotate(a, b, 'b');
// 			push_b(a, b);
// 		}
// 		else // b c a
// 		{
// 			push_b(a, b);
// 			reverse_rotate(a, b, 'b');
// 		}
// 	}
// 	else if (num[2] < num[0] && num[2] < num[1])
// 	{
// 		reverse_rotate(a, b, 'a');
// 		push_b(a, b);
// 		if (num[0] < num[1]) // c a b
// 		{
// 			reverse_rotate(a, b, 'b');
// 			push_b(a, b);
// 		}
// 		else // c b a
// 		{
// 			push_b(a, b);
// 			reverse_rotate(a, b, 'b');
// 		}
// 	}
// 	(*b)->pre->is_last = FALSE;
// 	(*a)->is_last = FALSE;
// 	(*a)->pre->is_last = FALSE;
// 	(*b)->is_last = TRUE;
// }
