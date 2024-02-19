/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_make_excep_asc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:38:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 18:52:12 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	excep_asc_to_b(t_node **a, t_node **b, int which)
{
	long long	num[3];
	int			flag[3];

	case_action(a, b, flag, FIR);
	del_flag_excep((*b)->pre, *a, FIR, which);
	while (*a)
	{
		change_num_asc(*a, *b, flag, num);
		del_flag_excep((*b)->pre, *a, MID, which);
		if (flag[0] == 2 && flag[1] == 2 && flag[2] == 2)
			break ;
		if (num[1] < num[0] && num[2] < num[0])
			case_action(a, b, flag, 1);
		else if (num[0] < num[1] && num[2] < num[1])
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

void	change_num_asc(t_node *a, t_node *b, int flag[], long long num[])
{
	num[0] = b->pre->val;
	num[1] = a->val;
	num[2] = a->pre->val;
	if (flag[0] >= 2)
		num[0] = INT_MIN;
	if (flag[1] >= 2)
		num[1] = INT_MIN;
	if (flag[2] >= 2)
		num[2] = INT_MIN;
}

void	case_action(t_node **a, t_node **b, int flag[], int which_case)
{
	if (which_case == FIR)
	{
		flag[0] = 0;
		flag[1] = 0;
		flag[2] = 0;
	}
	else if (which_case == 1)
	{
		reverse_rotate(a, b, 'b');
		flag[0]++;
	}
	else if (which_case == 2)
	{
		push_b(a, b);
		flag[1]++;
	}
	else if (which_case == 3)
	{
		reverse_rotate(a, b, 'a');
		push_b(a, b);
		flag[2]++;
	}
}
