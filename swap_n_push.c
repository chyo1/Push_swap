/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/23 11:10:09 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node *a)
{
	t_node	*fir;
	t_node	*sec;
	int		tmp;

	fir = a;
	sec = a->next;
	tmp = a->val;
	fir->val = sec->val;
	sec->val = tmp;
}

void	swap_b(t_node *b)
{
	t_node	*fir;
	t_node	*sec;
	int		tmp;

	fir = b;
	sec = b->next;
	tmp = b->val;
	fir->val = sec->val;
	sec->val = tmp;
}

void	swap_swap(t_node *a, t_node *b)
{
	swap_a(a);
	swap_b(b);
}

void	push_a(t_node **s1, t_node **s2)
{
	t_node	*a_fir;
	t_node	*a_sec;
	t_node	*b_fir;
	t_node	*b_sec;

	if (*s2 == NULL)
		return ;
	b_fir = *s2;
	b_sec = b_fir->next;

	a_fir = *s1;
	a_sec = a_fir->next;

	b_fir->next = a_fir;
	*s1 = b_fir;
	*s2 = b_sec;

}

void	push_b(t_node **s1, t_node **s2)
{
	t_node	*a_fir;
	t_node	*a_sec;
	t_node	*b_fir;
	t_node	*b_sec;

	if (*s2 == NULL)
		return ;
	b_fir = *s2;
	b_sec = b_fir->next;

	a_fir = *s1;
	a_sec = a_fir->next;

	a_fir->next = b_fir;
	*s2 = a_fir;
	*s1 = a_sec;
}
