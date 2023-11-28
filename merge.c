/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:46:44 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/28 14:57:34 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_div(t_node **a, t_node **b, int cnt, int order)
{
	int	i;

	i = 0;
	if (cnt < 6)
	{
		order_under_6(a, b, cnt, order);
		return ;
	}
	if (order == ASC)
	{
		init_div(a, b, cnt / 3, ASC);
		init_div(a, b, cnt / 3, DESC);
		init_div(a, b, cnt - 2 * (cnt / 3), DESC);
	}
	else if (order == DESC)
	{
		init_div(a, b, cnt / 3, DESC);
		init_div(a, b, cnt / 3, ASC);
		init_div(a, b, cnt - 2 * (cnt / 3), ASC);
	}
}

void	order_under_6(t_node **a, t_node **b, int cnt, int order)
{
	if (order == ASC)
	{
		if (cnt <= 2)
			asc_12(a, b, cnt);
		else if (cnt == 3)
			asc_3(a, b);
		else if (cnt == 4)
			asc_4(a, b);
		else if (cnt == 5)
			asc_5(a, b);
	}
	else if (order == DESC)
	{
		if (cnt <= 2)
			desc_12(a, b, cnt);
		else if (cnt == 3)
			desc_3(a, b);
		else if (cnt == 4)
			desc_4(a, b);
		else if (cnt == 5)
			desc_5(a, b);
	}
}
