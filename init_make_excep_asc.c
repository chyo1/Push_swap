/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excep_asc_merge_to_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:38:12 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/02 22:15:37 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	excep_asc_to_b(t_node **a, t_node **b, int which)
{
	int	num[3];
	int	flag[3];

	flag[0] = flag[1] = flag[2] = 0;
	del_flag_excep((*b)->pre, *a, FIR, which);
	while (*a)
	{
		num[0] = (*b)->pre->val; 	// end_b -> f
		num[1] = (*a)->val; 		// fir_a -> f
		num[2] = (*a)->pre->val; 	// end_a -> e
		if (flag[0] >= 2) // end_b -> end
			num[0] = INT_MIN;
		if (flag[1] >= 2) // fir_a -> end
			num[1] = INT_MIN;
		if (flag[2] >= 2) // end_a -> start
			num[2] = INT_MIN;

		del_flag_excep((*b)->pre, *a, MID, which);
		if (num[0] == INT_MIN && num[1] == INT_MIN && num[2] == INT_MIN)
			break ;
		if (num[1] < num[0] && num[2] < num[0])
		{
			reverse_rotate(a, b, 'b');
			if (!flag[0] && !flag[1] && !flag[2])
				(*b)->end = TRUE;
			flag[0]++;
		}
		else if (num[0] < num[1] && num[2] < num[1])
		{
			push_b(a, b);
			if (!flag[0] && !flag[1] && !flag[2])
				(*b)->end = TRUE;
			flag[1]++;
		}
		else
		{
			reverse_rotate(a, b, 'a');
			push_b(a, b);
			if (!flag[0] && !flag[1] && !flag[2])
				(*b)->end = TRUE;
			flag[2]++;
		}
	}
	while (flag[0]++ < 2)
		reverse_rotate(a, b, 'b');
	(*b)->start = TRUE;
}
