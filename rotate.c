/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:55 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/05 13:19:29 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **s1, t_node **s2, char which)
{
	if (which == 'a' && rotate_a(s1) == TRUE)
		write(1, "ra\n", 3);
	if (which == 'b' && rotate_b(s2) == TRUE)
		write(1, "rb\n", 3);
	if (which == 'c' && (rotate_a(s1) == TRUE || rotate_b(s2) == TRUE))
		write(1, "rr\n", 3);
}

int	rotate_a(t_node **s1)
{
	t_node	*node;

	node = pop_front(s1);
	if (node == NULL)
		return (FALSE);
	push_back(s1, node);
	return (TRUE);
}

int	rotate_b(t_node **s2)
{
	t_node	*node;

	node = pop_front(s2);
	if (node == NULL)
		return (FALSE);
	push_back(s2, node);
	return (TRUE);
}
