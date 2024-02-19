/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:32:24 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/13 12:19:01 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	char	*str;
	int		cnt_argv;

	head_a = NULL;
	head_b = NULL;
	str = NULL;
	if (argv_parsing(argc, argv, &head_a, &cnt_argv))
		return (0);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!do_str(str, &head_a, &head_b))
			return (fin_program(&head_a, &head_b, &str));
		free(str);
	}
	if (!head_b && head_a && check_order(head_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	fin_program(t_node **head_a, t_node **head_b, char **str)
{
	t_node	*del;
	t_node	*now;

	now = *head_a;
	while (*head_a && now->next != *head_a)
	{
		del = now;
		now = now->next;
		free(del);
	}
	free(now);
	now = *head_b;
	while (*head_b && now->next != *head_b)
	{
		del = now;
		now = now->next;
		free(del);
	}
	free(now);
	free(*str);
	return (0);
}

int	do_str(char *s, t_node **a, t_node **b)
{
	if (s[0] == 's')
	{
		if (s[2] == '\n' && (s[1] == 'a' || s[1] == 'b' || s[1] == 's'))
			return (swap(*a, *b, s[1]));
	}
	else if (s[0] == 'r')
	{
		if (s[2] == '\n' && (s[1] == 'a' || s[1] == 'b' || s[1] == 'r'))
			return (rotate(a, b, s[1]));
		else if (s[1] == 'r')
		{
			if (s[3] == '\n' && (s[2] == 'a' || s[2] == 'b' || s[2] == 'r'))
				return (reverse_rotate(a, b, s[2]));
		}
	}
	else if (s[0] == 'p')
	{
		if (s[2] == '\n' && s[1] == 'a')
			return (push_a(a, b));
		else if (s[2] == '\n' && s[1] == 'b')
			return (push_b(a, b));
	}
	write(1, "Error\n", 6);
	return (0);
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
