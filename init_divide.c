/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:46:44 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 17:33:41 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_div(t_node **a, t_node **b, int cnt, int order)
{
	if (cnt < 6)
		return (order_under_6(a, b, cnt, order));
	init_div(a, b, cnt / 3, ASC);
	if (cnt % 3 == 2)
	{
		if (order == ASC)
			init_div(a, b, cnt / 3 + 1, DESC);
		else if (order == DESC)
			init_div(a, b, cnt / 3 + 1, ASC);
		return (init_div(a, b, cnt / 3 + 1, DESC));
	}
	else
	{
		if (order == ASC)
			init_div(a, b, cnt / 3, DESC);
		else if (order == DESC)
			init_div(a, b, cnt / 3, ASC);
		return (init_div(a, b, cnt / 3 + cnt % 3, DESC));
	}
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
			asc_5(a, b, TRUE);
		else if (cnt == 6)
			asc_6(a, b);
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
			desc_5(a, b, TRUE);
		else if (cnt == 6)
			desc_6(a, b);
	}
}
