/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:19:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/27 16:03:48 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	unsigned int	i;
	t_node			*head_a;
	t_node			*head_b;

	i = 1;
	while (i < argc)
	{
		if (parsing(*argv[i]) == -1)
		{
			write(1, "Error", 2); // input error
			free_list(&root_a); /// free A stack
			free_list(&root_b); /// free B stack
			return (0);
		}
		i++;
	}
}
