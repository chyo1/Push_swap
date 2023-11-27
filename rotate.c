/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:55 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/27 14:59:10 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_last_node(t_node *node)
{
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	rotate(t_node **s1, t_node **s2, char which)
{
	if (which == 'a' && rotate_a(s1) == 1)
		write(1, "ra\n", 3);
	if (which == 'b' && rotate_b(s2) == 1)
		write(1, "rb\n", 3);
	if (which == 'c' && (rotate_a(s1) == 1 || rotate_b(s2) == 1))
		write(1, "rr\n", 3);
}
int	rotate_a(t_node **s1)
{
	t_node	*fir;
	t_node	*last;

	if (*s1 && (*s1)->next != NULL)
	{
		fir = *s1;
		last = get_last_node(fir);
		*s1 = fir->next;
		last->next = fir;
		fir->next = NULL;
		return (1);
	}
	return (0);
}
int	rotate_b(t_node **s2)
{
	t_node	*fir;
	t_node	*last;

	if (*s2 && (*s2)->next != NULL)
	{
		fir = *s2;
		last = get_last_node(fir);
		*s2 = fir->next;
		last->next = fir;
		fir->next = NULL;
		return (1);
	}
	return (0);
}
