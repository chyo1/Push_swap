/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:20:28 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/11/28 11:15:26 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int					val;
	int					is_last;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

// main.c
int		main(int argc, char **argv);

// parsing.c
void	check_space(const char **str);
void	check_sign(const char **str, int *minus);
int		parsing(const char *str, t_node **root);

// init_connect_del.c
int		make_node(t_node **head, int val);
void	free_list(t_node **head);

// push_pop.c
void	push_front(t_node **head, t_node *new);
void	push_back(t_node **head, t_node *new);
t_node	*pop_front(t_node **head);
t_node	*pop_back(t_node **head);

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

// init_make_asc.c
void	asc_2(t_node **a, t_node **b);
void	asc_3(t_node **a, t_node **b);
void	asc_4(t_node **a, t_node **b);
void	asc_5(t_node **a, t_node **b);

// init_make_desc.c
void	desc_2(t_node **a, t_node **b);
void	desc_3(t_node **a, t_node **b);
void	desc_4(t_node **a, t_node **b);
void	desc_5(t_node **a, t_node **b);
#endif
