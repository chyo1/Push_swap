/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:19:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/28 11:16:37 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_node	*head_a;
	t_node	*head_b;

	i = 1;
	head_a = NULL;
	head_b = NULL;
	while (i < argc)
	{
		if (parsing(argv[i], &head_a) == -1)
		{
			write(1, "Error", 2); // input error
			free_list(&head_a); /// free A stack
			free_list(&head_b); /// free B stack
			return (0);
		}
		i++;
	}
	// merge;
}
