/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_make_excep_desc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:38:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 16:11:41 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	excep_desc_to_b(t_node **a, t_node **b, int which)
{
	long long	num[3];
	int			flag[3];

	case_action(a, b, flag, FIR);
	del_flag_excep((*b)->pre, *a, FIR, which);
	while (*a)
	{
		change_num_desc(*a, *b, flag, num);
		del_flag_excep((*b)->pre, *a, MID, which);
		if (flag[0] == 2 && flag[1] == 2 && flag[2] == 2)
			break ;
		if (num[0] < num[1] && num[0] < num[2])
			case_action(a, b, flag, 1);
		else if (num[1] < num[0] && num[1] < num[2])
			case_action(a, b, flag, 2);
		else
			case_action(a, b, flag, 3);
		if (flag[0] + flag[1] + flag[2] == 1)
			(*b)->end = TRUE;
	}
	while (flag[0]++ < 2)
		reverse_rotate(a, b, 'b');
	(*b)->start = TRUE;
}

void	change_num_desc(t_node *a, t_node *b, int flag[], long long num[])
{
	num[0] = b->pre->val;
	num[1] = a->val;
	num[2] = a->pre->val;
	if (flag[0] >= 2)
		num[0] = INT_MAX;
	if (flag[1] >= 2)
		num[1] = INT_MAX;
	if (flag[2] >= 2)
		num[2] = INT_MAX;
}

void	del_flag_excep(t_node *e_b, t_node *f_a, int flag, int which)
{
	if (flag == FIR)
	{
		e_b->end = FALSE;
		f_a->end = FALSE;
		f_a->pre->start = FALSE;
		return ;
	}
	if (which == 16)
	{
		if (e_b->start == TRUE && e_b->pre->start == TRUE)
			e_b->start = FALSE;
		if (f_a->start == TRUE)
			f_a->start = FALSE;
		if (f_a->pre->end == TRUE)
			f_a->pre->end = FALSE;
	}
	else
	{
		if (e_b->start == TRUE && e_b->pre->start == TRUE)
			e_b->start = FALSE;
		if (f_a->start && !f_a->next->start && !f_a->next->end)
			f_a->start = FALSE;
		if (f_a->pre->end && !f_a->pre->pre->start && !f_a->pre->pre->end)
			f_a->pre->end = FALSE;
	}
}

void	init_make_put_num(t_node **a, int n[], int which)
{
	n[0] = (*a)->val;
	n[1] = ((*a)->next)->val;
	if (which == 3)
		n[2] = (*a)->pre->val;
	else
		n[2] = (((*a)->next)->next)->val;
	if (which >= 4)
		n[3] = ((*a)->pre)->val;
	if (which >= 5)
		n[4] = (((*a)->pre)->pre)->val;
	if (which >= 6)
		n[5] = (((*a)->pre)->pre->pre)->val;
}
