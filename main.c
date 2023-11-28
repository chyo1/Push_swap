/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:19:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/28 15:35:20 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_node	*head_a;
	t_node	*head_b;
	int		cnt;

	i = 1;
	cnt = 0;
	head_a = NULL;
	head_b = NULL;
	
	while (i < argc)
	{
		if (parsing(argv[i], &head_a, &cnt) == -1)
		{
			write(1, "Error\n", 6); // input error
			free_list(&head_a); /// free A stack
			return (0);
		}
		i++;
	}
	//print_list(&head_a);

	// merge;
	init_div(&head_a, &head_b, cnt, ASC);
}

#include <stdio.h>
void	print_list(t_node **head)
{
	t_node	*now;

	now = *head;
	while (now->next != *head)
	{
		printf("%d ", now->val);
		now = now->next;
	}
}