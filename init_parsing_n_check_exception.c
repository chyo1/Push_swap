/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:38 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/29 16:12:53 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_space(const char **str)
{
	while (**str && ((9 <= **str && **str <= 13) || **str == 32))
		(*str)++;
}

int	check_sign(const char **str)
{
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			return (-1);
		(*str)++;
	}
	return (1);
}

int	parsing(const char *str, t_node **head, int *cnt_argv)
{
	long long	num;
	int			minus;
	int			flag;

	while (*str)
	{
		num = 0;
		flag = 0;
		check_space(&str);
		minus = check_sign(&str, &minus);
	
		// check is digit
		while (*str && ('0' <= *str && *str <= '9'))
		{
			num = num * 10 + (*str - '0');
			// int range error
			if (minus * num < -2147483648 || minus * num > 2147483647)
				return (-1);
			str++;
			flag = 1;
		}

		// check blank input & malloc error
		if (!flag || make_node(head, minus * num) == -1)
			return (-1);
		(*cnt_argv)++;
	}
	return (1);
}

int	check_order(t_node *head)
{
	t_node	*now;

	now = head;
	while (now->next != head)
	{
		if (now->val > now->next->val)
			return (0);
		now = now->next;
	}
	return (1);
}

int	check_exep(int cnt)
{
	if (cnt < 6)
		return (0);
	if (cnt == 16 || cnt == 17)
		return (1);
	if (check_exep(cnt / 3) == 1)
		return (1);
	if (check_exep(cnt / 3) == 1)
		return (1);
	if (check_exep(cnt - 2 * (cnt / 3)) == 1)
		return (1);
	return (0);
}

