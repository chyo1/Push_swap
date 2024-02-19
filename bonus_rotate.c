/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:55 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/09 14:22:53 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotate(t_node **s1, t_node **s2, char which)
{
	if (which == 'a')
		rotate_a(s1);
	if (which == 'b')
		rotate_b(s2);
	if (which == 'r')
	{
		rotate_a(s1);
		rotate_b(s2);
	}
	return (TRUE);
}

void	rotate_a(t_node **s1)
{
	t_node	*node;

	node = pop_front(s1);
	if (node == NULL)
		return ;
	push_back(s1, node);
	return ;
}

void	rotate_b(t_node **s2)
{
	t_node	*node;

	node = pop_front(s2);
	if (node == NULL)
		return ;
	push_back(s2, node);
	return ;
}
