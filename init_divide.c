/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:46:44 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/30 20:14:18 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_div(t_node **a, t_node **b, int cnt, int order)
{
	int	i;

	// if (check_order(*a))
	// 	return ;
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
