/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:03:16 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/08 12:26:52 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:28 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/05 15:47:33 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //

typedef struct s_node
{
	long long		val;
	int				start;
	int				end;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

# define ASC 0
# define DESC 1

# define FALSE 0
# define TRUE 1

# define FIR 0
# define MID 1

# define INT_MAX 2147483648
# define INT_MIN -2147483649

// main.c
int		main(int argc, char **argv);
// void	print_list(t_node *head); //
// void	print_rev_list(t_node *head);
// int		check_excep(int cnt); //

// swap_n_push.c
int		swap_a(t_node *a);
int		swap_b(t_node *b);
void	swap(t_node *a, t_node *b, char which);
void	push_a(t_node **s1, t_node **s2);
void	push_b(t_node **s1, t_node **s2);

// rotate.c
void	rotate(t_node **s1, t_node **s2, char which);
int		rotate_a(t_node **s1);
int		rotate_b(t_node **s2);

// reverse_rotate.c
void	reverse_rotate(t_node **s1, t_node **s2, char which);
t_node	*get_prelast_node(t_node *node);
int		reverse_rotate_a(t_node **s1);
int		reverse_rotate_b(t_node **s2);

// under_6_code.c
void	order(t_node *a, t_node *b, int cnt);
void	order_2(t_node *a);
void	order_3(t_node *a, t_node *b);
void	order_4(t_node *a, t_node *b);
void	order_5(t_node *a, t_node *b);

// init_parsing_n_check_exception.c
void	check_space(const char **str);
int		check_sign(const char **str);
int		parsing(const char *str, t_node **root, int *cnt);
int		check_order(t_node *head);
int		check_excep(int cnt);

// init_connect_del.c
int		make_node(t_node **head, long long val);
void	free_list(t_node **head);

// init_make_excep_asc.c
void	excep_asc_to_b(t_node **a, t_node **b, int which);
// void	del_flag_b(t_node *end_b, *fir_a, int flag, int which);

// init_make_excep_desc.c
void	excep_desc_to_b(t_node **a, t_node **b, int which);
void	del_flag_excep(t_node *end_b, t_node *fir_a, int flag, int which);

// push_pop.c
void	push_front(t_node **head, t_node *new);
void	push_back(t_node **head, t_node *new);
t_node	*pop_front(t_node **head);
t_node	*pop_back(t_node **head);

// init_make_asc.c
void	asc_2(t_node **a, t_node **b);
void	asc_3(t_node **a, t_node **b, int is_start);
void	asc_4(t_node **a, t_node **b, int is_start);
void	asc_5(t_node **a, t_node **b);

// init_make_desc.c
void	desc_2(t_node **a, t_node **b);
void	desc_3(t_node **a, t_node **b, int is_start);
void	desc_4(t_node **a, t_node **b, int is_start);
void	desc_5(t_node **a, t_node **b);

// init_divide.c
void	init_div(t_node **a, t_node **b, int cnt, int order);
int		check_order(t_node *head);
void	order_under_6(t_node **a, t_node **b, int cnt, int order);
void	order_excep(t_node **a, t_node **b, int order, int which);
void	excep_merge_to_b(t_node **a, t_node **b, int order, int which);
void	init_div_excep(t_node **a, t_node **b, int cnt, int order);

// init_divide_excep.c
void	order_excep(t_node **a, t_node **b, int order, int which);
void	order_excep(t_node **a, t_node **b, int order, int which);
void	case_53(t_node **a, t_node **b, int order, int cnt);
void	excep_merge_to_b(t_node **a, t_node **b, int order, int which);

// merge.c
void	merge(t_node **a, t_node **b, int tri_size, int tri_cnt);
void	merge_to_a(t_node **a, t_node **b, int div);
void	merge_to_b(t_node **a, t_node **b, int div);
void	reverse_list_flag(t_node *head);

// merge_to_a.c
void	asc_to_a(t_node **a, t_node **b);
void	desc_to_a(t_node **a, t_node **b); //
void	del_flag_a(t_node *end_a, t_node *fir_b, t_node *end_b, int flag);

// merge_to_b.c
void	asc_to_b(t_node **a, t_node **b);
void	desc_to_b(t_node **a, t_node **b);
void	del_flag_b(t_node *end_b, t_node *fir_a, t_node *end_a, int flag);

#endif