/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:52:32 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/27 19:03:34 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **s1, t_node **s2, char which)
{
	if (which == 'a' && reverse_rotate_a(s1) == 1)
		write(1, "rra\n", 4);
	if (which == 'b' && reverse_rotate_b(s2) == 1)
		write(1, "rrb\n", 4);
	if (which == 'c' && (reverse_rotate_a(s1) == 1 || reverse_rotate_b(s2) == 1))
		write(1, "rrr\n", 4);
}

t_node	*get_prelast_node(t_node *node)
{
	t_node	*pre;
	t_node	*last;

	pre = node;
	last = node;
	while (last->next != NULL)
	{
		pre = last;
		last = last->next;
	}
	return (pre);
}

int	reverse_rotate_a(t_node **s1)
{
	t_node	*node;

	node = pop_back(s1);
	if (node == NULL)
		return (0);
	push_front(s1, node);
	return (1);
}

int	reverse_rotate_b(t_node **s2)
{
	t_node	*node;

	node = pop_back(s2);
	if (node == NULL)
		return (0);
	push_front(s2, node);
	return (1);
}

