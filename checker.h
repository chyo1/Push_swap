/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:32:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2023/12/09 14:56:39 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# define FALSE 0
# define TRUE 1
// # define NULL 0

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	int				fd;
	ssize_t			len;
	ssize_t			size;
	ssize_t			loc;
	struct s_list	*next;
}	t_list;

typedef struct s_node
{
	long long		val;
	int				start;
	int				end;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

// bonus_get_next_line.c
char	*get_next_line(int fd);
int		cpy_buff(t_list *node, char *buff, ssize_t cnt);
int		find_endl(t_list *node, ssize_t cnt);
char	*get_ans(t_list **root, t_list *node);

// bonus_get_next_line_utils.c
t_list	*find_or_make_lst(t_list **root, int fd);
int		init_node(t_list *node, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
char	*list_free_and_connect(t_list **lst, int fd);

// bonus_main.c
int		main(int argc, char **argv);
int		do_str(char *str, t_node **a, t_node **b);
int		argv_parsing(int argc, char **argv, t_node **a, int *cnt_argv);
int		fin_program(t_node **head_a, t_node **head_b, char **str);

// init_parsing_.c 
void	check_space(const char **str);
int		check_sign(const char **str);
int		parsing(const char *str, t_node **head, int *cnt_argv);
int		check_order(t_node *head);

// init_connect_del.c
int		make_node(t_node **head, int val);
void	free_list(t_node **head);

// bonus_reverse_rotate.c 
int		reverse_rotate(t_node **s1, t_node **s2, char which);
void	reverse_rotate_a(t_node **s1);
void	reverse_rotate_b(t_node **s2);

// bonus_rotate.c 
int		rotate(t_node **s1, t_node **s2, char which);
void	rotate_a(t_node **s1);
void	rotate_b(t_node **s2);

// bonus_swap_n_push.c 
int		swap(t_node *a, t_node *b, char which);
void	swap_a(t_node *a);
void	swap_b(t_node *b);
int		push_a(t_node **s1, t_node **s2);
int		push_b(t_node **s1, t_node **s2);

// push_pop.c
void	push_front(t_node **head, t_node *new_node);
void	push_back(t_node **head, t_node *new_node);
t_node	*pop_front(t_node **head);
t_node	*pop_back(t_node **head);

#endif
