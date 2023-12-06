/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:46:44 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/06 18:54:36 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_div(t_node **a, t_node **b, int cnt, int order)
{
	// if (check_order(*a))
	// 	return ;
	if (cnt == 14)
	{
		order_under_6(a, b, 4, ASC);
		if (order == ASC) // ㅇㅇㅈ
			order_under_6(a, b, 5, DESC);
		else if (order == DESC) // ㅇㅈㅈ
			order_under_6(a, b, 5, ASC);
		order_under_6(a, b, 5, DESC);
		return ;
	}
	if (cnt < 6)
	{
		order_under_6(a, b, cnt, order);
		return ;
	}
	init_div(a, b, cnt / 3, ASC);
	if (order == ASC) // ㅇㅇㅈ
		init_div(a, b, cnt / 3, DESC);
	else if (order == DESC) // ㅇㅈㅈ
		init_div(a, b, cnt / 3, ASC);
	return (init_div(a, b, cnt - 2 * (cnt / 3), DESC));
}

int	check_order(t_node *head)
{
	t_node	*now;

	now = head;
	while (now->next != head)
	{
		if (now->val > now->next->val)
			return (0);
		now = now->next;
	}
	return (1);
}
void	order_under_6(t_node **a, t_node **b, int cnt, int order)
{
	if (order == ASC)
	{
		if (cnt <= 2)
			asc_12(a, b, cnt);
		else if (cnt == 3)
			asc_3(a, b, TRUE);
		else if (cnt == 4)
			asc_4(a, b, TRUE);
		else if (cnt == 5)
			asc_5(a, b);
	}
	else if (order == DESC)
	{
		if (cnt <= 2)
			desc_12(a, b, cnt);
		else if (cnt == 3)
			desc_3(a, b, TRUE);
		else if (cnt == 4)
			desc_4(a, b, TRUE);
		else if (cnt == 5)
			desc_5(a, b);
	}
}
void	order_excep(t_node **a, t_node **b, int order, int which)
{
	if (order == ASC) // ㅈㅈㅇ
	{
		order_under_6(a, b, 2, ASC); //  1 bottom_a  ASC
		order_under_6(a, b, 2, ASC); //  2 top_a     DESC
		order_under_6(a, b, 2, ASC); //  3 bottom_b  ASC
		exep_merge_to_b(a, b, ASC, which);
	}
	else // ㅇㅇㅈ
	{
		order_under_6(a, b, 2, DESC); // bottom_a  DESC
		order_under_6(a, b, 2, DESC); //  top_a    ASC
		order_under_6(a, b, 2, DESC); //  bottom_b DESC
		exep_merge_to_b(a, b, DESC, which);
	}
}
void	exep_merge_to_b(t_node **a, t_node **b, int order, int which)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		(*b)->start = FALSE;
		(*b)->end = FALSE;
		// start = true
		if (i == 0 || i == 2 || i == 5)
			(*b)->start = TRUE;
		// end = true
		else if (i == 1 || i == 3 || i == 4)
			(*b)->end = TRUE;

		// bottom_b
		if (i < 2)
			rotate(a, b, 'b');
		// top_a
		else if (i < 4)
			push_a(a, b);
		// bottom_a
		else
		{
			push_a(a, b);
			rotate(a, b, 'a');
		}
		i++;
	}
	// printf("\n--------------exep-----------\n");
	// print_list(*a);
	// print_list(*b);
	// asc
	if (order == ASC)
		exep_asc_to_b(a, b, which);
	// desc
	else
		exep_desc_to_b(a, b, which);

	// printf("\n-------------check_flag-----------\n");
	// print_list(*a);
	// print_list(*b);

	// reverse flag
	t_node *last = *b;
	while (last->end != TRUE)
		last = last->next;
	last->end = FALSE;
	last->start = TRUE;
	(*b)->start = FALSE;
	(*b)->end = TRUE;

	// printf("\n--------------reverse flag-----------\n");
	// print_list(*a);
	// print_list(*b);
}

void	init_div_exep(t_node **a, t_node **b, int cnt, int order)
{
	if (cnt == 14)
	{
		order_under_6(a, b, 4, ASC);
		if (order == ASC) // ㅇㅇㅈ
			order_under_6(a, b, 5, DESC);
		else if (order == DESC) // ㅇㅈㅈ
			order_under_6(a, b, 5, ASC);
		order_under_6(a, b, 5, DESC);
		return ;
	}
	else if (cnt == 16)
	{
		init_div(a, b, 5, ASC);
		if (order == ASC) // ㅇㅇㅈ
			init_div(a, b, 5, DESC);
		else if (order == DESC) // ㅇㅈㅈ
			init_div(a, b, 5, ASC);
		return (order_excep(a, b, DESC, 16));
	}
	else if (cnt == 17)
	{
		init_div(a, b, 5, ASC);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 16));
	}
	else if (cnt == 18)
	{
		order_excep(a, b, ASC, 17);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 16));
	}
	else if (cnt == 53)
	{
		// // order_excep(a, b, 17, DESC);
		// init_div(a, b, 5, ASC);
		// if (order == ASC) // ㅇㅇㅈ
		// 	order_excep(a, b, DESC, 17);
		// else if (order == DESC) // ㅇㅈㅈ
		// 	order_excep(a, b, ASC, 17);
		// order_excep(a, b, DESC, 17);

		// // order_excep(a, b, DESC, 18)
		// if (order == ASC) // ㅇㅇㅈ
		// {
		// 	order_excep(a, b, ASC, 17);
		// 	if (order == ASC) // ㅇㅇㅈ
		// 		order_excep(a, b, ASC, 17);
		// 	else if (order == DESC) // ㅇㅈㅈ
		// 		order_excep(a, b, DESC, 17);
		// 	order_excep(a, b, DESC, 17);
		// }
		// else if (order == DESC) // ㅇㅈㅈ
		// {
		// 	order_excep(a, b, ASC, 17);
		// 	if (order == ASC) // ㅇㅇㅈ
		// 		order_excep(a, b, ASC, 17);
		// 	else if (order == DESC) // ㅇㅈㅈ
		// 		order_excep(a, b, DESC, 17);
		// 	order_excep(a, b, DESC, 17);
		// }
		// // order_excep(a, b, 18, DESC);
		// order_excep(a, b, ASC, 17);
		// if (order == ASC) // ㅇㅇㅈ
		// 	order_excep(a, b, ASC, 17);
		// else if (order == DESC) // ㅇㅈㅈ
		// 	order_excep(a, b, DESC, 17);
		// order_excep(a, b, DESC, 16);
		// return ;
		case_53(a, b, order, cnt);
		return ;
	}
	if (cnt < 6)
	{
		order_under_6(a, b, cnt, order);
		return ;
	}
	init_div_exep(a, b, cnt / 3, ASC);
	if (order == ASC) // ㅇㅇㅈ
		init_div_exep(a, b, cnt / 3, DESC);
	else if (order == DESC) // ㅇㅈㅈ
		init_div_exep(a, b, cnt / 3, ASC);
	return (init_div_exep(a, b, cnt - 2 * (cnt / 3), DESC));
}

void	case_53(t_node **a, t_node **b, int order, int cnt)
{
	if (cnt == 17)
	{
		init_div(a, b, 5, ASC);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 17));
	}
	else if (cnt == 18)
	{
		order_excep(a, b, ASC, 17);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 17));
	}
	else if (cnt == 19) // last 18
	{
		order_excep(a, b, ASC, 17);
		if (order == ASC) // ㅇㅇㅈ
			order_excep(a, b, DESC, 17);
		else if (order == DESC) // ㅇㅈㅈ
			order_excep(a, b, ASC, 17);
		return (order_excep(a, b, DESC, 16));
	}
	else if (cnt == 53)
	{
		case_53(a, b, ASC, 17);
		if (order == ASC)
			case_53(a, b, DESC, 18);
		else
			case_53(a, b, ASC, 18);
		// if (is_last_div(*a))
			return (case_53(a, b, DESC, 19));
		// else 
		// 	return (case_53(a, b, DESC, 18));
	}

	// if (cnt < 6)
	// 	return (order_under_6(a, b, cnt, order));

	// init_div_exep(a, b, cnt / 3, ASC);
	// if (order == ASC) // ㅇㅇㅈ
	// 	init_div_exep(a, b, cnt / 3, DESC);
	// else if (order == DESC) // ㅇㅈㅈ
	// 	init_div_exep(a, b, cnt / 3, ASC);
	// return (init_div_exep(a, b, cnt - 2 * (cnt / 3), DESC));
}

int is_last_div(t_node *a)
{
	int	cnt;
	t_node	*now;

	cnt = 0;
	now = a;
	while (now->next != a)
	{
		cnt++;
		now = now->next;
	}
	if (cnt + 1 == 6)
		return (1);
	return (0);
}