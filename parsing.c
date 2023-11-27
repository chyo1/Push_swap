/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:38 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/27 15:58:53 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_space(const char **str)
{
	while (**str && ((9 <= **str && **str <= 13) || **str == 32))
		(*str)++;
}

static void check_sign(const char **str, int *minus)
{
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*minus = -1;
		(*str)++;
	}
}

int	parsing(const char *str, t_node **root)
{
	long long	num;
	int			minus;
	int			flag;

	while (*str)
	{
		num = 0;
		flag = 0;
		minus = 1;
		check_space(&str);
		check_sign(&str, minus);
		while (*str && ('0' <= *str && *str <= '9'))
		{
			num = num * 10 + (*str - '0');
			if (minus * num < -2147483648 || minus * num > 2147483647)
				return (-1); // num range error
			str++;
			flag = 1;
		}
		// check blank input & malloc error
		if (!flag || make_node(root, minus * num) == -1)
			return (-1);
	}
	return (1);
}
