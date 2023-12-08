/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:46:44 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 12:23:33 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_div(t_node **a, t_node **b, int cnt, int order)
{
	// change 4 4 6 -> 4 5 5
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
	// when cnt is over 6 -> have to divide
	init_div(a, b, cnt / 3, ASC);
	if (order == ASC) // ㅇㅇㅈ
		init_div(a, b, cnt / 3, DESC);
	else if (order == DESC) // ㅇㅈㅈ
		init_div(a, b, cnt / 3, ASC);
	init_div(a, b, cnt - 2 * (cnt / 3), DESC);
	return ;
}

void	order_under_6(t_node **a, t_node **b, int cnt, int order)
{
	if (order == ASC)
	{
		if (cnt <= 2)
			asc_2(a, b);
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
			desc_2(a, b);
		else if (cnt == 3)
			desc_3(a, b, TRUE);
		else if (cnt == 4)
			desc_4(a, b, TRUE);
		else if (cnt == 5)
			desc_5(a, b);
	}
}
