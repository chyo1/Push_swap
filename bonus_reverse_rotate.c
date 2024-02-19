/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:52:32 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/09 14:26:18 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	reverse_rotate(t_node **s1, t_node **s2, char which)
{
	if (which == 'a')
		reverse_rotate_a(s1);
	if (which == 'b')
		reverse_rotate_b(s2);
	if (which == 'r')
	{
		reverse_rotate_a(s1);
		reverse_rotate_b(s2);
	}
	return (TRUE);
}

void	reverse_rotate_a(t_node **s1)
{
	t_node	*node;

	node = pop_back(s1);
	if (node == NULL)
		return ;
	push_front(s1, node);
	return ;
}

void	reverse_rotate_b(t_node **s2)
{
	t_node	*node;

	node = pop_back(s2);
	if (node == NULL)
		return ;
	push_front(s2, node);
	return ;
}
