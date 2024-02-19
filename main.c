/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:19:41 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/01/14 17:19:00 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		cnt_argv;
	int		is_excep;

	head_a = NULL;
	head_b = NULL;
	if (argv_parsing(argc, argv, &head_a, &cnt_argv) || check_order(head_a))
		return (0);
	if (cnt_argv < 6)
		return (order(head_a, head_b, cnt_argv));
	is_excep = check_excep(cnt_argv);
	if (is_excep)
		init_div_excep(&head_a, &head_b, cnt_argv, ASC);
	else
		init_div(&head_a, &head_b, cnt_argv, ASC);
	merge(&head_a, &head_b, cnt_argv, 1);
	if (head_a == NULL)
	{
		while (head_b)
		{
			reverse_rotate(&head_a, &head_b, 'b');
			push_a(&head_a, &head_b);
		}
	}
}

int	argv_parsing(int argc, char **argv, t_node **a, int *cnt_argv)
{
	int	i;

	i = 1;
	*cnt_argv = 0;
	if (argc == 1)
		return (-1);
	while (i < argc)
	{
		if (parsing(argv[i], a, cnt_argv) == -1)
		{
			write(1, "Error\n", 6);
			free_list(a);
			return (-1);
		}
		i++;
	}
	return (0);
}
