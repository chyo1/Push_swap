/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:19:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 12:25:25 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_node	*head_a;
	t_node	*head_b;
	int		cnt_argv;
	int		is_excep;

	// init
	i = 1;
	cnt_argv = 0;
	head_a = NULL;
	head_b = NULL;

	while (i < argc)
	{
		if (parsing(argv[i], &head_a, &cnt_argv) == -1)
		{
			write(1, "Error\n", 6); // input error
			free_list(&head_a); // free A stack
			return (0);
		}
		i++;
	}

	// check whether number is ordered ascending
	if (check_order(head_a))
		return (0);

	// simple sort
	if (cnt_argv < 6)
	{
		order(head_a, head_b, cnt_argv);
		return (0);
	}

	// exception case check : 16, 17, 53 is exception
	is_excep = check_excep(cnt_argv);
	if (is_excep)
		init_div_excep(&head_a, &head_b, cnt_argv, ASC);
	else
		init_div(&head_a, &head_b, cnt_argv, ASC);

	// sorting
	merge(&head_a, &head_b, cnt_argv, 1);

	// if sorting is ended in stack_B, we have to move numbers to stack_A
	if (head_a == NULL)
	{
		// sorted to ASC order
		while (head_b)
		{
			reverse_rotate(&head_a, &head_b, 'b');
			push_a(&head_a, &head_b);
		}
	}
}

// void	print_list(t_node *head)
// {
// 	t_node	*now;

// 	now = head;
// 	if (head == NULL)
// 		return ;
// 	//printf("\n----print_list----\n");
// 	while (now->next != head)
// 	{
// 		printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
// 		if (now->start == TRUE)
// 			printf("-----------------\n");
// 		now = now->next;
// 	}
// 	printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
// 	printf("\n-----------------------------\n");
// 	printf("\n");
// }

// void	print_rev_list(t_node *head)
// {
// 	t_node	*now;

// 	now = head;
// 	if (head == NULL)
// 		return ;
// 	//printf("\n----print_list----\n");
// 	while (now->next != head)
// 	{
// 		printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
// 		if (now->end == TRUE)
// 			printf("-----------------\n");
// 		now = now->next;
// 	}
// 	printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
// 	printf("-----------------------------");
// 	printf("\n");
// }