/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:19:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/06 19:47:26 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_node	*head_a;
	t_node	*head_b;
	int		cnt;
	int 	flag; //

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
	if (check_order(head_a))
		return (0);
	if (cnt < 6)
	{
		init_div(&head_a, &head_b, cnt, DESC);
		while (head_b)
			push_a(&head_a, &head_b);
		return (0);
	}
	flag = check_exep(cnt);
	// printf("flag : %d\n", flag);
	if (flag)
		init_div_exep(&head_a, &head_b, cnt, ASC);
	else
		init_div(&head_a, &head_b, cnt, ASC);
	// printf("\n----init divide to b----\n");
	// print_list(head_b);
	// printf("\n------------merge-------------\n");
	merge(&head_a, &head_b, cnt, 1);
	// print_list(head_b);
	if (head_a == NULL)
	{
		while (head_b)
		{
			reverse_rotate(&head_a, &head_b, 'b');
			push_a(&head_a, &head_b);
		}
	}
}

void	print_list(t_node *head)
{
	t_node	*now;

	now = head;
	if (head == NULL)
		return ;
	//printf("\n----print_list----\n");
	while (now->next != head)
	{
		printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
		if (now->start == TRUE)
			printf("-----------------\n");
		now = now->next;
	}
	printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
	printf("\n-----------------------------\n");
	printf("\n");
}

void	print_rev_list(t_node *head)
{
	t_node	*now;

	now = head;
	if (head == NULL)
		return ;
	//printf("\n----print_list----\n");
	while (now->next != head)
	{
		printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
		if (now->end == TRUE)
			printf("-----------------\n");
		now = now->next;
	}
	printf("s: %d e: %d val: %lld\n", now->start, now->end, now->val);
	printf("-----------------------------");
	printf("\n");
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
