/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:19:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/02 15:48:16 by hyowchoi         ###   ########.fr       */
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
	cnt = 0; // cnt_argv
	head_a = NULL;
	head_b = NULL;
	
	while (i < argc)
	{
		if (parsing(argv[i], &head_a, &cnt) == -1)
		{
			write(1, "Error\n", 6); // input error
			free_list(&head_a); // free A stack
			return (0);
		}
		i++;
	}
	init_div(&head_a, &head_b, cnt, ASC);
	// printf("\n cnt : %d\n", cnt);
	printf("\n----init divide to b----\n");
	// print_list(head_b);
	merge(&head_a, &head_b, cnt, 1);
	if (head_a == NULL)
	{
		while (head_b)
		{
			reverse_rotate(&head_a, &head_b, 'b');
			push_a(&head_a, &head_b);
		}
	}
	printf("\nresult\n");
	print_list(head_a);
}

void	print_list(t_node *head)
{
	t_node	*now;

	now = head;
	if (head == NULL)
		return ;
	printf("\n----print_list----\n");
	while (now->next != head)
	{
		printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
		now = now->next;
	}
	printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
	printf("\n");
}