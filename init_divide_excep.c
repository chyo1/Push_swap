/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_divide_excep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:31:04 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 17:33:24 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_div_excep(t_node **a, t_node **b, int cnt, int order)
{
	if (cnt <= 6)
		return (order_under_6(a, b, cnt, order));
	init_div_excep(a, b, cnt / 3, ASC);
	if (cnt % 3 == 2)
	{
		if (order == ASC)
			init_div_excep(a, b, cnt / 3 + 1, DESC);
		else if (order == DESC)
			init_div_excep(a, b, cnt / 3 + 1, ASC);
		return (init_div_excep(a, b, cnt / 3 + 1, DESC));
	}
	else
	{
		if (order == ASC)
			init_div_excep(a, b, cnt / 3, DESC);
		else if (order == DESC)
			init_div_excep(a, b, cnt / 3, ASC);
		return (init_div_excep(a, b, cnt / 3 + cnt % 3, DESC));
	}
}

void	init_div_excep_under_18(t_node **a, t_node **b, int cnt, int order)
{
	if (cnt == 16 || cnt == 17)
	{
		if (cnt == 16)
			order_under_6(a, b, 5, ASC);
		else
			asc_6(a, b);
		if (order == ASC)
			order_under_6(a, b, 5, DESC);
		else if (order == DESC)
			order_under_6(a, b, 5, ASC);
		return (desc_6(a, b));
	}
}
