/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_6_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:01:42 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/06 20:07:19 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_node *a, t_node *b, int cnt)
{
	if (cnt == 2)
		swap_a(a);
	else if (cnt == 3)
		return (order_3(a, b));
	else if (cnt == 4)
		return (order_4(a, b));
	else if (cnt == 5)
		return (order_5(a, b));
}
void	order_3(t_node *a, t_node *b)
{
	
}

void	order_4(t_node *a, t_node *b)
{
	
}

void	order_5(t_node *a, t_node *b)
{
	
}
