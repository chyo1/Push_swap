/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:19:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/29 18:20:47 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_node	*head_a;
	t_node	*head_b;
	int		cnt[2];

	i = 1;
	cnt[0] = 0; // cnt_argv
	cnt[1] = 1; // cnt_divided
	head_a = NULL;
	head_b = NULL;
	
	while (i < argc)
	{
		if (parsing(argv[i], &head_a, &cnt[0]) == -1)
		{
			write(1, "Error\n", 6); // input error
			free_list(&head_a); // free A stack
			return (0);
		}
		i++;
	}
	init_div(&head_a, &head_b, cnt[0], ASC);
	merge(&head_a, &head_b, cnt, TO_A);
}

void	print_list(t_node **head)
{
	t_node	*now;

	now = *head;
	if (*head == NULL)
		return ;
	while (now->next != *head)
	{
		printf("%d ", now->val);
		now = now->next;
	}
	printf("%d ", now->val);
	printf("\n");
}