/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_n_check_exception.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:38 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 16:54:06 by hyowchoi         ###   ########.fr       */
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
	if (**str && (**str == '+' || **str == '-'))
	{
		if (**str == '-')
		{
			(*str)++;
			return (-1);
		}
		(*str)++;
	}
	return (1);
}

int	parsing(const char *str, t_node **head, int *cnt_argv)
{
	long long	num;
	int			minus;

	if (*str == '\0')
		return (-1);
	while (*str)
	{
		num = 0;
		check_space(&str);
		minus = check_sign(&str);
		if (!('0' <= *str && *str <= '9'))
			return (-1);
		while (*str && ('0' <= *str && *str <= '9'))
		{
			num = num * 10 + (*str - '0');
			if (minus * num < -2147483648 || minus * num > 2147483647)
				return (-1);
			str++;
		}
		if (make_node(head, minus * num) == -1)
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

int	check_excep(int cnt)
{
	if (cnt < 6)
		return (0);
	if (cnt == 16 || cnt == 17)
		return (1);
	if (check_excep(cnt / 3) == 1)
		return (1);
	if (cnt % 3)
		if (check_excep(cnt / 3 + 1) == 1)
			return (1);
	return (0);
}
